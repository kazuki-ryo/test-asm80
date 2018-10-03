#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"common.h"

#include"mac_z80.h"

unsigned char Memory[32768];

int main(int argc,char* argv[])
{
	char *readfile=DEFAULT_FILE;
	printf("assembler version 0.1\n");

	char tmp[256];
	char ch1[256],ch2[256],ch3[256],ch4[256];
	int i,a,b;
	unsigned char* outputMemory=Memory;
	int totalByte=0;
    int line_num=1;
	FILE* fp=fopen(readfile,"r");
	for(i=0;i<20;i++){
		//fscanf(fp,"%s",tmp);
		//one line read.
		tmp[0]=0;
		fgets(tmp,254,fp);tmp[255]=0;
		if(strlen(tmp)>=254){
			ErrorMessage(STATUS_ERROR,"Line buffer over.","");
			exit(1);
		}
		char code[100],op1[100],op2[100];
		char label[100],tmp2[200];
		char* next;
		//next=split(tmp,label,':');
		int result=split_rl(tmp,label,tmp2,':');
		//printf("tmp2=%s result=%d\n",tmp2,result);
		if(result==1){
			//LABEL nothing
			next=split(tmp2,code,' ');
			next=split(next,op1,',');
			next=split(next,op2,',');
		}else{
			//LABEL exist
			next=split(label,code,' ');
			next=split(next,op1,',');
			next=split(next,op2,',');
			label[0]=0;
		}

		printf("[%s]:[%s] [%s] [%s]\n",label,code,op1,op2);
		int count,a;
		count=getCode(outputMemory,code,op1,op2,0);
		if(count>0){
			for(a=0;a<count;a++){
				printf("%02x,",outputMemory[a]);
			}
			printf("\n");
			outputMemory+=count;
			totalByte+=count;
		}
		
		if(feof(fp)!=0){
			break;
		}
	}
	fclose(fp);
	printf("assemble complate!\n");
	printf("total bytes=%d \n",totalByte);

	return 0;
}


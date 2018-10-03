/*
Target:z80 to code
*/

#include<string.h>
#include<stdio.h>

int ErrorCode=0;
char RegSet8[8][3]={"B","C","D","E","H","L","","A"};
char RegSet16[4][3]={"BC","DE","HL","SP"};
char FlagType[8][3]={"NZ","Z","NC","C","PO","PE","P","M"};

int getRegNumber8(char* regname)
{
	int i;
	for(i=0;i<8;i++){
		if(*regname == RegSet8[i][0]){
			return i;
		}
	}
	return -1;
}
int getFlagTypeNumber(char* flagname)
{
	int i;
	for(i=0;i<8;i++){
		if(flagname[0] == FlagType[i][0] && flagname[1] == FlagType[i][1]){
			return i;
		}
	}
	return -1;
}
/*
param:
code is execute
op1,op2,op3 is parameter
result:
code bytes
*/
int getCode(unsigned char* output,char* code,char* op1,char* op2,char*op3)
{
	if(ErrorCode!=0){return 0;}
	int outbytes=0;
	int num1,num2;

	if(strcmp(code,"NOP")==0){
		output[0]=0;
		outbytes=1;
	}else if(strcmp(code,"LD")==0){
		num1=getRegNumber8(op1);
		num2=getRegNumber8(op2);
		output[0]=0x40 | num1*8 | num2;
		outbytes=1;
		if(num1>=0 && num2>=0){
			
		}else{
			printf("register name not found!");
		}
	}else if(strcmp(code,"EX")==0){
	}else if(strcmp(code,"EXX")==0){
	}else if(strcmp(code,"PUSH")==0){
	}else if(strcmp(code,"POP")==0){
	}else if(strcmp(code,"JR")==0){
	}else if(strcmp(code,"JP")==0){
	}else if(strcmp(code,"CALL")==0){
	}else if(strcmp(code,"RET")==0){
		if(op1[0]==0){
			output[0]=0xc9;
		}else{
			num1=getFlagTypeNumber(op1);
			if(num1>=0){
				output[0]=0xc0 | num1*8;
			}
		}
		outbytes=1;
	}

	return outbytes;
}


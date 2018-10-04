/*
Target:z80 to code
*/

#include<string.h>
#include<stdio.h>

int ErrorCode=0;
char RegSet8[8][3]={"B","C","D","E","H","L","","A"};
char RegSet16[4][3]={"BC","DE","HL","SP"};
char RegSet16af[4][3]={"BC","DE","HL","AF"};
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
	char code_op1_op2[100];
	if(op1[0]!=0 && op2[0]!=0){
		sprintf(code_op1_op2,"%s %s,%s",code,op1,op2);
	}else if(op1[0]!=0 && op2[0]==0){
		sprintf(code_op1_op2,"%s %s",code,op1);
	}else{
		strcpy(code_op1_op2,code);
	}
	
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
	}else if(strcmp(code,"ADD")==0){
	}else if(strcmp(code,"ADC")==0){
	}else if(strcmp(code,"INC")==0){
	}else if(strcmp(code,"SUB")==0){
	}else if(strcmp(code,"SBC")==0){
	}else if(strcmp(code,"DEC")==0){
	}else if(strcmp(code,"AND")==0){
	}else if(strcmp(code,"OR")==0){
	}else if(strcmp(code,"XOR")==0){
	}else if(strcmp(code,"BIT")==0){
	}else if(strcmp(code,"SET")==0){
	}else if(strcmp(code,"RES")==0){
	}else if(strcmp(code,"CP")==0){
	}else if(strcmp(code,"IN")==0){
	}else if(strcmp(code,"OUT")==0){
	}else{
//		printf("code_op1_op2=%s\n",code_op1_op2);

		if(strcmp(code_op1_op2,"PUSH AF")==0){
			outbytes=1;output[0]=0xf5;
		}else if(strcmp(code_op1_op2,"PUSH IX")==0){
			outbytes=2;output[0]=0xdd;output[1]=0xe5;
		}else if(strcmp(code_op1_op2,"PUSH IY")==0){
			outbytes=2;output[0]=0xfd;output[1]=0xe5;
		}else if(strcmp(code_op1_op2,"POP AF")==0){
			outbytes=1;output[0]=0xf1;
		}else if(strcmp(code_op1_op2,"POP IX")==0){
			outbytes=2;output[0]=0xdd;output[1]=0xe1;
		}else if(strcmp(code_op1_op2,"POP IY")==0){
			outbytes=2;output[0]=0xfd;output[1]=0xe1;
		}
	}

	return outbytes;
}


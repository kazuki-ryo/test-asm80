#define DEFAULT_FILE "test.mac"
#define STATUS_ERROR 1
#define STATUS_INFO 2
#define STATUS_DEBUG 3

void ErrorMessage(int type,char* msg,char* code){
	switch(type){
		case STATUS_ERROR:
			printf("ERROR: %s %s\n",msg,code);
		break;
		case STATUS_INFO:
			printf("INFO: %s %s\n",msg,code);
		break;
		case STATUS_DEBUG:
			printf("DEBUG: %s %s\n",msg,code);
		break;
	}
}

char* split(char* in,char* out,char regrex)
{
	while(*in!=0 && *in!=10 && *in!=13){
		if(*in==regrex){
			*out=0;in++;break;
		}
		*out++ = *in++;
	}
	*out=0;
	return in;
}

int split_rl(char* in,char* outl,char* outr,char regrex)
{
//	outl=in;
	int result=0;
	*outl=*outr=0;
//	printf("in=%s\n",in);
	while(*in!=0 && *in!=10 && *in!=13){

		if(*in==regrex){
			*outl=0;in++;//outr=in;
			while(*in!=0 && *in!=10 && *in!=13){
				*outr++ = *in++;
			}
			*outr=0;
			result=1;
			break;
		}
//		printf("in=%d ",*in);
		*outl++ = *in++;
	}
	*outl=0;
	return result;
}

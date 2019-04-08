#include<stdio.h>
#include"base64.h"
#include<string.h>
#include<stdlib.h>

int main()
{
	unsigned char *in="base64_test";
	int inlen=BASE64_DECODE_OUT_SIZE(strlen(in));
printf("%d\n",inlen);
printf("%s\n",in);
	char *out=(char*)malloc(sizeof(char)*inlen);

	swBase64_encode(in,strlen(in),out);

	printf("src=%s,dst=%s\n",in,out);
}

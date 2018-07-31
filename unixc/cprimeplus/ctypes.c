#include "public.h"
#include<ctype.h>//字符验证处理函数

int main()
{
	//isalpha:判断字符是否是字母
	//是：返回非0（eg:1024）;否：返回0
	int num=50;
	char ch='5';
	printf("%c\n",ch);
	printf("%hd\n",isalpha(ch));
	return 0;
}

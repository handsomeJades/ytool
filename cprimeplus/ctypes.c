#include "public.h"
#include<ctype.h>//字符验证处理函数

int main()
{
	//isalpha:判断字符是否是字母
	//是：返回非0（eg:1024）;否：返回0
	int num=50;
	printf("%c\n",num);
	printf("%hd\n",isalpha(num));
	return 0;
}

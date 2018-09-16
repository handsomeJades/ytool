/*
 *	macro tests
 */
#include<stdio.h>

#define TY_LINK(x) M##x
#define TY_SYBOLETOSRTRING(y) #y

int main()
{
	int a=2,b=3;
	int ab=a*b;
	printf("%s\n",TY_SYBOLETOSRTRING(a));
	int TY_LINK(one)=10;
	printf("%d\n",Mone);
	//printf("%s\n",TY_SYBOLETOSRTRING(TY_LINK(a,b)));
}

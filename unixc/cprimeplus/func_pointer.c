#include<stdio.h>
typedef int (*and_f)(int,int); //函数指针重定义
int And(int a,int b);
int main()
{
	and_f f=And;
	
	int result=f(1,2);
	printf("%d\n",result);
}

int And(int a,int b)
{
	return a+b;
}

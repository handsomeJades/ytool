#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void pr_d(const int *d);
void pr_s(const char *msg);

int main()
{
	//字符串栈分配
	char name[]="clock";

	memset(name,'0',sizeof(name)-1);
	//	printf("%X\n",sizeof name);	
	name[0]='C';
	//print format
	//	printf("%+5.3d\n",10);
	pr_s(name);

	//const variable,the pointer is point to a address 
	char *birth="199xxx";
	//char birth2[10]=birth;
	char birth3[10];
	char * birth2=birth3;
	strcpy(birth2,birth);
	printf("%10s\n",birth2);
	//birth[0]='2';
	//pr_s(birth);

	const int n=100;
	//	int n=200;
	//	pr_d(&n);
	//
	//字面值常量

}

void pr_d(const int * d)
{
	int m=30;
	d=&m;
	printf("%d\n",*d);	
}

void pr_s(const char *msg)
{
	char *another="efg";
	//	msg[0]=2;
	printf("%s\n",msg);
	exit(0);
}


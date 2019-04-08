#include "cplusplus.h"

int sum(int,int);
int sum(int,int,int);

int sum(int a,int b)
{
	return a+b;
}

int sum(int a,int b,int c)
{
	return a+b+c;
}

int main()
{
	cout<<sum(1,2)<<endl;
	cout<<sum(1,2,3)<<endl;
}

#include<stdio.h>
#pragma pack(2)
struct {
		long ll;
		char aa;
		int cc;
		short bb;
}A;

struct  BB
{
		int a;
		char b;
		double c;
		char d;
};
int main()
{
		printf("%d\n",sizeof(struct BB));
		printf("%d\n",sizeof(long));
}

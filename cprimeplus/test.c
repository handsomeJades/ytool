#include "public.h"
#define LEN 10
int main(int argc,char **argv)
{
	printf("%s\n",argv[0]);
	return 0;
	//int s[LEN]={1,2,3};
	int n;	
	scanf("%d",&n);
	printf("%d\n",n);
	//VLA
	int s[n];
	s[0]=123;

	printf("%d\n",s[0]);
}

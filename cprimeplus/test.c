#include "public.h"
#define LEN 10
#define PR(x) printf("the var "#x"=%d\n",(x))
int main(int argc,char **argv)
{
	assert(1==2);
	int m=100;
	PR(m);
	return 0;

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

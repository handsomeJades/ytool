#include<stdio.h>
#include"public.h"
#include<inttypes.h>
int main()
{
//	printf("%d\n",sizeof(short));
//	printf("%d\n",sizeof(int));
//	printf("%d\n",sizeof(long));
//	printf("%d\n",sizeof(long long int));
//	printf("%c\n",'c');
//	printf("%d\n",sizeof(_Bool));
	float f=1.45f;
	//printf("%d\n",sizeof(f));
	printf("%06.3f\n",f);
	short n;
	printf("%zd\n",sizeof(n));
	
	int a=199;
	prd(a);
	
	return 0;
}

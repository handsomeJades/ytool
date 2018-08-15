#include<stdio.h>

int main()
{
	int n=100;
	while(n--)
	{
#ifdef TEST 
		printf("%d ",n);
#endif
		system("curl 127.0.0.1:8080");
	}
	printf("\n");
}

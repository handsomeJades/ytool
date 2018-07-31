#include<stdio.h>
#include<limits.h>
#include<unistd.h>

int main()
{
	//printf("%ld\n",OPEN_MAX);	
	
	//long open_max=sysconf(_SC_OPEN_MAX);
	long open_max=fpathconf('/',_PC_PATH_MAX);
	printf("%ld\n",open_max);	
}

#include"include/apue.h"
#include<unistd.h>

int main()
{
	execlp("/usr/bin/env","env",NULL);	

	return 0;
}

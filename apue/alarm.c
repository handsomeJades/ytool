#include "include/apue.h"

static void handler(int);
int main()
{
	if(signal(SIGALRM,handler)==SIG_ERR){
		puts("error");
		exit(0);
	}

	puts("alarm started:");
	//return 0;
	alarm(3);

	pause();

    printf("%d\n",alarm(0));

	return 0;
}

static void handler(int signo)
{
	puts("alarm handler");
}




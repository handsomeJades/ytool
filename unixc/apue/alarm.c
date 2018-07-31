#include "include/apue.h"

static void handler(int);
static void sig_int(int);
int main()
{
	if(signal(SIGALRM,handler)==SIG_ERR){
		puts("error");
		exit(0);
	}
	if(signal(SIGINT,sig_int)==SIG_ERR){
		puts("error");
		exit(0);
	}

	while(1){
		putchar('1');
	}

	puts("alarm started:");
	//return 0;
//	alarm(3);

//	while(1){
		pause();//进程阻塞
		printf("%d\n",alarm(1));
//	}
	return 0;
}

static void handler(int signo)
{
	puts("alarm handler");
}

static void sig_int(int signo){

	puts("called sig_int");
}




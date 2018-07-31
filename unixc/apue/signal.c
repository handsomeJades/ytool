/*
 * signal():创建信号并设置回调
 */
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
static void sig_user(int signo);
static void sig_abort(int signo);
int main()
{

	//printf("%d",signal(SIGUSR1,sig_user));
	//printf("%d",SIG_ERR);
	if(signal(SIGUSR1,sig_user)==SIG_ERR)
	{
		printf("error");
	}	

	if(signal(SIGABRT,sig_abort)==SIG_ERR){
		puts("error");
	}
	
	abort();
	//return 0;
	///	signal(SIGUSR2,sig_user);	
	//signal(SIGUSR3,sig_user);	

	puts("after abort");
	//while(1)
//	{	
		//printf("s\n");
		pause();
//	}	

}

static void sig_user(int signo)
{
	if(signo==SIGUSR1)
		printf("recieved SIGUSR1\n");
	else if(signo==SIGUSR2)
		printf("recieved SIGUSR2\n");
	else
		printf("no handler");

}

static void sig_abort(int signo)
{
	puts("called abort/stop");
	return;
}

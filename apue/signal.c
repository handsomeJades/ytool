/*
 * signal():创建信号并设置回调
 */
#include<signal.h>
#include<stdio.h>
static void sig_user(int signo);
int main()
{
	//printf("%d",signal(SIGUSR1,sig_user));
	//printf("%d",SIG_ERR);
	if(signal(SIGUSR1,sig_user)==SIG_ERR)
	{
		printf("error");
	}	
	//return 0;
	signal(SIGUSR2,sig_user);	
	//signal(SIGUSR3,sig_user);	

	while(1)
	{	
		//printf("s\n");
		pause();
	}	

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

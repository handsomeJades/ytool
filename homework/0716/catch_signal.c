#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
static void sig_handle(int);

int main()
{
	if(signal(SIGINT,sig_handle)==SIG_ERR){
		puts("SIGINT信号处理函数注册失败");
		exit(-1);
	}
	if(signal(SIGUSR1,sig_handle)==SIG_ERR){
		puts("SIGUSR1信号处理函数注册失败");
		exit(-1);
	}

	while(1){
		pause();
	}
	return 0;
}

/*
 * SIGINT自定义信号处理函数
 */
static void sig_handle(int signo)
{
	switch(signo){
		case SIGINT:
			//puts("SIGINT触发了sig_handle()");
			fprintf(stdout,"SIGINT触发了sig_handle()\n");
			exit(0);
		case SIGUSR1:
			puts("SIGUSR1触发了sig_handle()");	
			break;
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<syslog.h>

void sig_usr1(int);
#define LEN 100
int main()
{
	FILE *fp=popen("ps -ef | grep a.out","r");
	if(fp==NULL){
		puts("daemon error");
		exit(1);
	}

	char ret[LEN];
	if(fgets(ret,LEN,fp)){
		puts(ret);
		printf(ret);
	}
		
	printf("ret is %d\n",atoi(ret));
	return 0;

	if(-1==daemon(0,0)){
		puts("daemon error");
		exit(1);
	}
	
	pid_t pid;

	if((pid=fork())<0){
		puts("daemon error");
		exit(1);
	}else if(pid==0){
		daemon(0,0);
		puts("child");
		sleep(10);
		exit(0);
	}

	

	syslog(LOG_USER | LOG_DEBUG,"child pid = %d\n",pid);
	int status;
	wait(&status);

	waitpid();

	if(signal(SIGUSR1,sig_usr1)==SIG_ERR){
		syslog(LOG_USER | LOG_DEBUG,"syslog produced!");
		exit(1);
	}

	//while(1)
		pause();
}

void sig_usr1(int signo)
{
	syslog(LOG_USER | LOG_DEBUG,"syslog produced!");
}


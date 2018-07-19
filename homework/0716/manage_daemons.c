#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<syslog.h>

#define LEN 1000
#define PROCESS_NUM 10

void create_process();

int main()
{

	if(-1==daemon(0,0)){
		puts("daemon error");
		exit(1);
	}

	//创建子进程
	int i;
	for(i=0;i<PROCESS_NUM;i++)
		create_process();

	//维护子进程数量
	FILE *fp=NULL;
	int active_proc_num;
	char ret[LEN];
	while(1){
		active_proc_num=0;
		fp=popen("ps -ef|grep a.out|grep -v grep|wc -l","r");	
		if(fp==NULL){
			syslog(LOG_USER | LOG_ERR,"popen error");
		}

		if(fgets(ret,sizeof(ret),fp)){
			active_proc_num=atoi(ret);
		}

		if(active_proc_num<PROCESS_NUM+1){
			create_process();
		}
	}
	
	return 0;
}

/**
 * 创建子进程
 */
void create_process(){
	pid_t pid;
	int status;
	if((pid=fork())<0){
		puts("fork error");
		exit(1);
	}else if(pid==0){   
		if(-1==daemon(0,0)){
			syslog(LOG_USER | LOG_ERR,"child daemon error");
			exit(1);
		}
		syslog(LOG_USER | LOG_DEBUG,"new child pid = %ld\n",getpid());
		sleep(5);
		exit(0);
	}
	waitpid(pid,NULL,0);
}

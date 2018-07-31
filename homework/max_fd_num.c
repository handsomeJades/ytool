#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/resource.h>

int main()
{
	//系统描述符数量上限
    struct rlimit cur_rlimit;
	if(getrlimit(RLIMIT_NOFILE,&cur_rlimit)==-1){
		perror("getrlimit error");
		exit(1);
	}
	printf("the soft limit is %d, the hard limit is %d\n",cur_rlimit.rlim_cur,cur_rlimit.rlim_max);

	//设置软限制为1000 硬限制为2000
	cur_rlimit.rlim_cur=1000;
	cur_rlimit.rlim_max=2000;
	if(setrlimit(RLIMIT_NOFILE,&cur_rlimit)){
		perror("setrlimit error");
		exit(1);
	}

	int newfd,maxfd;
	int fd_num=dup(STDIN_FILENO)+1;
	while((newfd=dup(STDIN_FILENO))!=-1){
			maxfd=newfd;
			fd_num++;
			printf("%d ",newfd);
	}
	fflush(STDIN_FILENO);
	perror("\ndup error because of ");
	printf("fd total num = %d ",fd_num);
	printf("\nmax fd = %d\n",maxfd);

	return 0;
}

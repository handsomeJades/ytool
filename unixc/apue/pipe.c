#include "include/apue.h"

int main()
{
	int n;
	int fd[2];
	pid_t pid;
	char line[15];
	//create semi-pipe
	if(pipe(fd)<0){
		perror("pipe");
	}

	if((pid=fork())<0){
		perror("创建进程");
	}else if(pid>0) {
		puts("this is parent process...");
		close(fd[0]);
		write(fd[1],"hello world\n",20);
	}else{
		puts("this is child process...");
		close(fd[1]);
		n=read(fd[0],line,20);
		puts(line);
	}

	return 0;

}

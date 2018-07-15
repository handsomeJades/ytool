#include"apue.h"
int main()
{
	pid_t pid;
	int status;

	if((pid=fork())<0){
		puts("fork error");
	}else if(pid==0){
		puts("i am child process,i will quit");
		sleep(2);
		exit(0);
	}

	wait(&status);
	puts("123");
}

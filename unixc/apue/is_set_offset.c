#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	if(lseek(STDIN_FILENO,0,SEEK_CUR)== -1){
		puts("can not seek");
	}else{
		puts("seek ok");
	}
	return 0;
}

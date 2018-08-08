#include<stdio.h>
#include<fcntl.h>

#define MAX 500
int main()
{
	int fd=open("/etc/hosts",O_RDONLY);
	
	char buf[MAX];
	//lseek(fd,10,SEEK_CUR);
	int n=read(fd,buf,100);	
	printf("%d\n",n);
	puts(buf);

	printf("%d\n",fd);

}

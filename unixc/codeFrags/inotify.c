/* 
 * inotify 监控文件变化，执行某个操作
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/inotify.h>

#define BUF_SIZE 1024
int main()
{
	daemon(0,0);
	struct inotify_event *event;

	int fd=inotify_init();
	if(fd<0)
	{
		perror("inotify_init");
		exit(1);
	}

	int wd=inotify_add_watch(fd,"/root/",IN_CLOSE_WRITE);
	if(wd<0)
	{
		perror("add");
		exit(1);
	}

	char buffer[BUF_SIZE];
	int len,index;
	while(len = read(fd, buffer, BUF_SIZE))
	{
		index = 0;
		while(index < len)
		{
			event = (struct inotify_event *)(buffer + index);
			if (event->wd != wd)
				continue;
			if((event->mask & IN_CLOSE_WRITE)
					&&(strcmp(event->name,"important.txt")==0
						||strcmp(event->name,"important1.txt")==0
					  )){
				printf("file %s is closed for writing.\n", event->name);
				system("date >> /root/inoify.txt");
			}

			index += sizeof(struct inotify_event) + event->len;
		}
	}
	

	return 0;
}

#include <stdio.h>
#include <sys/inotify.h>
#include <string.h>
#define MAX_BUFFER_SIZE 4096
int main()
{
	int fd, wd;
	int len, index;
	char buffer[2048];
	struct inotify_event * event;
	char *path = "/root/";

	if((fd = inotify_init()) <0)
	{
		printf("Failed to initialize inotify\n");
		return 1;
	}

	if((wd = inotify_add_watch(fd, path, IN_CLOSE_WRITE)) < 0)
	{
		printf("Can't add watch for %s\n", path);
		return 1;
	}
	while(len = read(fd, buffer, MAX_BUFFER_SIZE))
	{
		index = 0;
		while(index < len)
		{

			event = (struct inotify_event *)(buffer + index);
			if (event->wd != wd)
				continue;
			if(event->mask & IN_CLOSE_WRITE)
				printf("file %s is closed for writing.\n", event->name);
			else if(event->mask & IN_CREATE)
				printf("file %s is created.\n", event->name);

			index += sizeof(struct inotify_event) + event->len;
		}
	}
	return 0;


}

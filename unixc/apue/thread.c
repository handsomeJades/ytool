#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

static void* thread1(void * argv){
	sleep(5);
	puts("thread 1");
	printf("thread id = %ld\n",pthread_self());
}
int main()
{
	pthread_t tid;
	printf("main thread id = %ld\n",pthread_self());

	if(pthread_create(&tid,NULL,thread1,NULL)!=0)
	{
		puts("create thread wrong\n");
		exit(1);
	}

	pthread_join(tid,NULL);

	puts("after join");
	printf("main process id = %ld\n",getpid());

	return 0;
}

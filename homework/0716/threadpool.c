#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//jobs queue
struct job
{
	int id;
	struct job * next;
};

//thread pool
struct threadpoll
{
	pthread_mutex_t queue_mutex;
	pthread_cond_t queue_cond;
	struct job * job_head; //the head of job queue
	int destroy;
	pthread_t *tids; //thread array
	int max_thread_num;
	int jobs_num;
};

static struct threadpoll *poll;

void init_poll(int);
void *job_func(void * arg);
void printids();

int main()
{
	//init poll
	init_poll(5);


	return 0;
}

void init_poll(int max_num)
{
	poll=(struct threadpoll*)malloc(sizeof(struct threadpoll));

	pthread_mutex_init(&(poll->queue_mutex),NULL);
	pthread_cond_init(&(poll->queue_cond),NULL);

	poll->job_head=NULL;
	poll->destroy=0;
	poll->max_thread_num=max_num;
	poll->jobs_num=0;

	poll->tids=(pthread_t *)malloc(max_num*sizeof(pthread_t));
	int i=0;
//	printf("%d\n",max_num);
//	exit(1);
	int err;
	for(i=0;i<max_num;i++)
	{
		err=pthread_create(&(poll->tids[i]),NULL,job_func,NULL);
		if(err!=0)
		{
			puts("wrong");
			exit(1);
		}
	}


	//printf("%lu\n",poll->tids[0]);

	sleep(10);
}

void *job_func(void * arg)
{
	
	printids();
}

void add_job()
{
	job *newjob=();
}

void printids()
{
	pthread_t tid=pthread_self();
	printf("randnum is %d,thread id is %lu \n",6,(unsigned long)tid);
}













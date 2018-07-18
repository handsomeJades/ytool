#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//任务队列
struct job
{
	int id;
	struct job * next;
};

//线程池
struct threadpool
{
	pthread_mutex_t queue_mutex;
	pthread_cond_t queue_cond;
	struct job * job_head; //任务队列头
	struct job * job_tail; //任务队列尾
	int destroy;
	pthread_t *tids; //线程id集合
	int max_thread_num;
	int jobs_num;
};

static struct threadpool *pool;
static int job_id=1;
#define JOB_NUM 20000

void init_pool(int);
void *job_func(void *);
void printids(int);
void add_job();

int main()
{
	//init pool
	init_pool(5);

	int i;
	for(i=0;i<JOB_NUM;i++)
		add_job();

	sleep(5);
	/*printf("%d\n",pool->jobs_num);
	struct job * ptr=pool->job_head;
	while(ptr){
		printf("job id:%d\n",ptr->id);
		ptr=ptr->next;
	}*/

	return 0;
}

void init_pool(int max_num)
{
	pool=(struct threadpool*)malloc(sizeof(struct threadpool));

	pthread_mutex_init(&(pool->queue_mutex),NULL);
	pthread_cond_init(&(pool->queue_cond),NULL);

	pool->job_head=NULL;
	pool->destroy=0;
	pool->max_thread_num=max_num;
	pool->jobs_num=0;

	pool->tids=(pthread_t *)malloc(max_num*sizeof(pthread_t));
	int i=0;
//	printf("%d\n",max_num);
//	exit(1);
	for(i=0;i<max_num;i++)
	{
		pthread_create(&(pool->tids[i]),NULL,job_func,NULL);
	}


	//printf("%lu\n",pool->tids[0]);

}

void *job_func(void * arg)
{
//	printids();
//	return;
	int job_id; 
	while(1){
		pthread_mutex_lock(&(pool->queue_mutex));
		while(pool->jobs_num==0 && !pool->destroy){
			pthread_cond_wait(&(pool->queue_cond),&(pool->queue_mutex));
		}

		if(pool->destroy==1){
			pthread_mutex_unlock(&(pool->queue_mutex));
			pthread_exit(NULL);
		}

		pool->jobs_num--;
		job_id=pool->job_head->id;
		pool->job_head=pool->job_head->next;

		pthread_mutex_unlock(&(pool->queue_mutex));
		
		printids(job_id);
	}
	

}

void add_job()
{
	struct job *newjob=(struct job *)malloc(sizeof(struct job));
	newjob->next=NULL;
	newjob->id=job_id++;
	pthread_mutex_lock(&(pool->queue_mutex));

	//struct job *head=pool->job_head;
	//struct job *tail=pool->job_tail;
	if(pool->job_head==NULL){
		pool->job_head=newjob;
		pool->job_tail=newjob;
	}else{	
		pool->job_tail->next=newjob;
		pool->job_tail=newjob;
	}


	assert(pool->job_head!=NULL);
	
	pool->jobs_num++;
	pthread_mutex_unlock(&(pool->queue_mutex));

	pthread_cond_signal(&(pool->queue_cond));
	
}



void printids(int job_id)
{
	//srand(time(NULL));
	srand(job_id);
	pthread_t tid=pthread_self();
	printf("job id is %d,randnum is %d,thread id is %lu \n",job_id,rand(),(unsigned long)tid);
}













#include<stdio.h>
#include<ucontext.h>
#include<stdlib.h>

#define STACK_SIZE (1024*1024) 
#define CO_CAPICITY 10 

#define handle_error(msg) \
	    do { perror(msg); exit(EXIT_FAILURE); } while (0)

#define CO_READ 0
#define CO_READY 1
#define CO_RUNNING 2
#define CO_SUSPEND 3
struct coroutine
{
	int id;
	int status;
	ucontext ctx;
	co_f func;
	void *ud;
	struct schedule *sch;
};

struct schedule{
	char stack[STACK_SIZE];
	ucontext_t main;
	int running_co_id;
	int nco;
	int capicity;
	struct coroutine ** co;
};

typedef schedule * sch_t;
typedef void (* co_f)(sch_t sch_p,void *ud);

inline sch_t schedule_start()
{
	sch_t sch_p=malloc(sizeof(struct schedule));
	assert(NULL!=sch_p);
	sch_p->nco=0;
	sch_p->running_co_id=-1;
	sch_p->cap=CO_CAPICITY;
	sch_p->co=calloc(CO_CAPICITY,sizeof(struct coroutine *));
	return sch_p;
}


int co_yield();

int co_resume();

int co_ready();

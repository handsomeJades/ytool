#include"co.h"
int co_create(sch_t sch_p,co_f func,void *ud)
{
	struct coroutine * co_p=_co_new(sch_p,func,ud);
	int i;
	for(i=0;i<sch_p->capicity;i++)
	{
		int id=(i+sch_p->nco)%sch_p->capicity;
		if(NULL==sch_p->co[id])
		{
			sch_p->co[id]=co_p;
			++ sch_p->nco;
			return id;
		}
	}
	return -1;
	
}

static inline struct coroutine * _co_new(sch_t sch_p,co_f func,void *ud)
{
	struct coroutine * co_p=malloc(sizeof(struct coroutine));

	co_p->func=func;
	co_p->ud=ud;
	co_p->sch=sch_p;
	co_p->status=CO_READY;

	return co_p;
}

void co_consume(sch_t sch_p,int co_id)
{
	co=sch_p->co[id];
	if(co==NULL || co->status==CO_READ){
		return;
	}

	switch(sch_p->status){
		case CO_READY:
			sch_p->running_co_id=id;
			co->status=CO_RUNNING;
			getcontext(&co->ctx);
			co->ctx.uc_stack.ss_sp=sch_p->stack;
			co->ctx.uc_stack.ss_size=STACK_SIZE;
//			co->ctx.uc_link=&sch_p->;
			makecontext();

	}
}





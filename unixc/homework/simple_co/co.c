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





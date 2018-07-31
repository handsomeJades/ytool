#include"include/link_table.h"
#include<stdio.h>
#include<malloc.h>

int main(){
	struct node head;
	nptr headptr=&head;
    headptr->data=10;
	nptr p_tail=(nptr)malloc(sizeof(struct node));
	p_tail->data=20;
	headptr->next=p_tail;
	
	nptr p=headptr;
	while(p!=NULL){
	 printf("%d--\n",p->data);			
	 p=p->next;
	}

	//printf("%d\n",headptr->data);			
	//printf("%d\n",p_tail->data);			
	return 0;
}

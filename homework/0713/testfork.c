/*
 * parent process and child process share the same fp
 * ,and they write to the fp at the same time,what happend?
 * the result is that the parent process be excuted firsty.
 * but in fact,it is random and depends on the schdule.
 */
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fp;
	if((fp=fopen("output.txt","rw+"))==NULL)
			err_sys("fopen error");

	pid_t pid;
	if((pid=fork())<0){
		err_sys("fork_error");
	}else if(pid>0){
		int i;
		for(i=10;i<15;i++){
			fprintf(fp,"Hi %d!\n",i);
		//	fprintf(stdout,"parent %d!\n",i);
		//	sleep(0.5);
		}
	}else{
		int i;
//////////////////		for(i=0;i<5;i++)
		//	fprintf(fp,"Hello %d!\n",i);
//			fprintf(stdout,"child %d!\n",i);
	}

	fclose(fp);

	return 0;
	

}

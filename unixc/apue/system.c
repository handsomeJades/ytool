#include"include/apue.h"

int main()
{
	//	system("date > tmp/date");

	raise(SIGFPE);

	//int ret = system("date");
	int ret = system("data");

	int status=-1;
	printf("exit code = %d\n",WEXITSTATUS(ret));
	return 0;
}

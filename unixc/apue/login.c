#include<stdio.h>
#include<unistd.h>

int main()
{
	char* logininfo=getlogin();

	printf("%s\n",logininfo);



}

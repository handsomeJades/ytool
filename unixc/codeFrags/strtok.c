#include<stdio.h>
#include<string.h>

int main()
{
	char buf[]="1@2@3@4@5";
	char *temp=strtok(buf,"@");

	while(temp){
		printf("%s ",temp);
		temp=strtok(NULL,"@");
	}
	return 0;
}



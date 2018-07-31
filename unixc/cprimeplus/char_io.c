#include<stdio.h>

int swap1(int,int);
int main()
{
	//字符串io
	FILE * fp=fopen("tmp.txt","rw+");
	char buffer[100];
	fgets(buffer,10,fp);
	fputs(buffer,stdout);

	char *s=buffer;
	sprintf(s,"%d+%d\n",1,2);
	puts(s);
	return 0;
	printf("%d\n",sizeof(stdin));
		
	fprintf(fp,"Hello %s!\n","jades");

	char a[10];
	scanf("%*s");
	scanf("%s",a);
	printf("%s\n",a);
	printf("%d\n",swap1(1,2));

	fputs("jades",stdout);
}

int swap1(int a,int b){
	return 6;

}

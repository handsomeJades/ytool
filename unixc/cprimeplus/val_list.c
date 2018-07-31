#include<stdio.h>
#include<stdarg.h>

double average(int num,...)
{
	va_list valist; /*分配可变参数分配内存*/
	
	va_start(valist,num); /*初始化*/

	int i;
	double sum=0.0;
	//int sum=0;
	int argv;
	for(i=0;i<num;i++){
		argv=va_arg(valist,int); /*获取可变参数*/
		printf("参数%d为%d\n",i,argv); 
		sum = sum+argv;
	}

	printf("%f,%hd\n",sum,num); //注意转换说明
	va_end(valist);
	
	return sum/num;
}

int main(int argc,char *argv){
	//可变数量参数
	printf("average = %6.2f",average(4,2,3,4,5));

	return 0;
}

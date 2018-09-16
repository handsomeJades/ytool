#include "public.h"

int main()
{
	int ar[]={3,4,5};
    printf("total bytes: %d\n",sizeof ar);

	int i;
	int *p_arr=ar;
	printf("start address:%p\n",ar+1);
	printf("start address:%p\n",ar);
    printf("指针差值为: %hd\n",(ar+1)-ar);
	for(i=0;i<sizeof ar / sizeof(int);i++)
	{
	//	printf("%d\n",p_arr[i]);
		printf("%d\n",*(p_arr++));	//使用后缀++，先使用后自增（优雅写法）
	}
}

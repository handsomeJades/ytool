#include<iostream>

int main()
{
	using namespace std;
	int *p=nullptr;
	cout<<sizeof(p)<<endl;
	int *arr=new int[10]{1,2,3,4,5,6,7,8,9,10};	
	//arr[0]=222;
	cout<<sizeof(*arr)<<endl;
//	for(int i=0;i<10;i++)
//			cout<<arr[i]<<endl;
    int arr1[10]{1,2,3,4,5,6,7,8,9,10};
	p=arr1;
	cout<<sizeof(p)<<endl;
	for(int x : arr1)
			cout<<x<<endl;
}

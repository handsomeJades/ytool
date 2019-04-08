#include "cplusplus.h"
#include<array>

int main()
{
	std::array<int,3> arr={1,2,3};
	arr[0]=4;
	for (int i : arr)
		cout<<i<<endl;
}

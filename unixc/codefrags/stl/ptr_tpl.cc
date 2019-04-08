#include "cplusplus.hpp"
#include<unistd.h>

int main()
{
	unique_ptr<int> ptr(new int);
	*ptr=1234;
	cout<<*ptr<<endl;

}

#include "cplusplus.h"


int main()
{
		auto lb=[](int x)->double{return x%3;};

		cout<<lb(8)<<endl;
		cout<<lb(9)<<endl;
}

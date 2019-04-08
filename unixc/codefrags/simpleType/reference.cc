#include<iostream>
using namespace std;

inline int sum(int & a,const int & b){
		a=15;
		int c=a+b;
		return c;
}

int main()
{
		int a=10;
		int& ar=a;

		int b=20;
		int c=sum(a,b);
		cout<<c<<endl;

		cout<<a<<' '<<ar<<endl;
}


#include"simple_type.hpp"

int main()
{
	int a=10;
	int b=20;
	swapT(a,b);
	cout<<"整型：";
	cout<<a<<" "<<b<<endl;

	char char_a='a';
	char char_b='b';
	swapT(char_a,char_b);

	cout<<"整型：";
	cout<<char_a<<" "<<char_b<<endl;
}

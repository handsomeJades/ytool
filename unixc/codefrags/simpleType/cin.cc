#include<iostream>

int main()
{
	using std::endl;
	struct Foo{
		int n;
		Foo(){
			std::cout<<"Enter n:"<<endl;
			std::cin>>n;
		}
	};

	Foo foo;
	
	std::cout<<"f.n is "<<foo.n<<endl;
}

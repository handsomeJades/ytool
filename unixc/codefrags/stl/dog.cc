#include<iostream>
#include"test.h"
#include<unistd.h>
using namespace std;

class Dog {
		public :
				int weight;
				Dog(int w)
				{
						this->weight=w;
				}

				void setWeight(int new_w){
						this->weight=new_w;
				}

};

int main()
{
		Dog myDog=Dog(10);
		myDog.setWeight(999);
		cout<<myDog.weight<<endl;
		show("dog...");
		cout<<getpid()<<endl;
		if(fork()){
				cout<<11<<endl;
				exit(0);
		}
		wait();
		cout<<22<<endl;
}

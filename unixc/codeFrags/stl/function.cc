#include<iostream>
#include<string>
using namespace std;

struct {
	string operator()(string text){
		return text+":---";
	}
} appendText;

int main()
{
	string rtn=appendText("2019");
	cout<<rtn<<endl;
}

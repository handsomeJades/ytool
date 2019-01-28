#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

static void show(int n){
	cout<<"valus is :"<<n<<endl;
}
int main(){
		//两个vector
		vector<int> v[2];

	//添加数据
		v[0].push_back(1);
		v[0].push_back(2);
		v[1].push_back(3);
		for(vector<int>::iterator it=v[1].begin();it!=v[1].end();it++){
				cout<<*it<<endl;
		}

		for_each(v[0].begin(),v[0].end(),show);

		string s="hello world";
		for(char s : s)
				cout<<s<<endl;
}

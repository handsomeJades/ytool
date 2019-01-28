#include<iostream>
#include<map>
#include<string>
int main()
{
	using namespace std;
	map<int,string> dogMap;
	dogMap.insert(pair<int,string>(1,"aa"));
	dogMap.insert(pair<int,string>(2,"bb"));
	dogMap.insert(pair<int,string>(3,"cc"));

	pair<int,string> p(6,"construct pair");
	auto auto_pair=make_pair(8,"make pair");
	dogMap.insert(p);
	dogMap.insert(auto_pair);
	map<int,string>::reverse_iterator iter;
	for(iter=dogMap.rbegin();iter!=dogMap.rend();iter++){
		cout<<iter->first<<' '<<iter->second<<endl;
	}
}

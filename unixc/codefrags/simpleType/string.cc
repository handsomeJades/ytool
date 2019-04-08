#include<iostream>
#include<string>
using namespace std;

int main()
{
		string longer("umm,this is a funny hat.");
		int loc1=longer.find("this");
		cout<<loc1<<endl;

		const unsigned desired_length(8);
		string long_string("where is the end?");
		string short_string("Ha");

		cout << "before--->" << long_string << std::endl;
		long_string.resize(desired_length);
		cout << "after--->" << long_string << std::endl;

		cout << "before--->" << short_string << std::endl;
		short_string.resize(desired_length, 'x');
		cout << "after--->" << short_string << std::endl;

		std::string s;
		try
		{
				s.resize(s.max_size() - 1, 'a');
		}
		catch (const std::exception &e)
		{
				std::cerr << e.what() << '\n';
		}

		 cout<<sizeof(wchar_t)<<std::endl;
}

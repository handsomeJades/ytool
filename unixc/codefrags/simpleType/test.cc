#include <iostream>
#include <clocale>
#include <string>
#include <cwchar>
#include <cstdio>

void print_wide(const std::wstring& wstr)
{
		std::mbstate_t state {};
		for(wchar_t wc : wstr) {
				std::string mb(MB_CUR_MAX, '\0');
				std::size_t ret = std::wcrtomb(&mb[0], wc, &state);
				std::cout<<mb;
				//std::cout << "multibyte char " << mb << " is " << ret << " bytes\n";
		}
}

int main()
{
		std::string wstr = "z栈哈哈中文编码绝不"; // 或 L"zß水������"
//		print_wide(wstr);
//		std::wcout<<wstr;
//		wprintf(L"111测试中文!\n");
		std::cout<<wstr;
		printf("111测试中文!\n");
}

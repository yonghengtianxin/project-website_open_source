#include <iostream>
#include <fstream>
#include <string>
#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib") 
using namespace std;
int main()
{
    char* get = getenv("QUERY_STRING");
	string str;
/*	int pos = 0;
	int strpos = 0;
	int i = 0;
	char chs[2] = { 0 };
	char* p = nullptr;
	char ret = 0;
*/

	char* 返回的字符串 = new char[strlen(get)+1];
	char* 传入的字符串 = new char[strlen(get)+1];
	strcpy(传入的字符串,get);
	DWORD 字符串长度 = strlen(get)+1;
	
	UrlUnescapeA(传入的字符串, 返回的字符串, &字符串长度, NULL);

	string getstr = 返回的字符串;

	if (getstr.find(".") != string::npos) {
		cout << "Content-type:text/html;charset=GB18030\r\n\r\n";
		cout << "<p>你不觉得有什么问题吗</p>\n";
		return 0;
	}

	ifstream fs(".\\text\\"+getstr);
	if (fs)
	{
		cout << "Content-type:text/html;charset:utf-8\r\n\r\n";
		while (fs.peek() != EOF)
		{
			getline(fs, str);
			cout << str << "\n";
		}
	}
	else
	{
		cout << "Content-type:text/html;charset=GB18030\r\n\r\n";
		cout << "<p>找不到指定的内容</p>\n";
		cout << "<p>请求内容为" << getstr << "</p>\n";
		cout << "<p>get请求原始内容：" << get << "</p>\n";
		cout << "<p>解码传入的字符串：" << 传入的字符串 << "</p>\n";
		cout << "<p>解码返回的字符串" << 返回的字符串 << "</p>\n";
	}
}
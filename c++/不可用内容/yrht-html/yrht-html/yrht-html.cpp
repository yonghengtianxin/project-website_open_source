#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string yrht() {
	
}

int main()
{
	char* get = getenv("QUERY_STRING");
	string getstr = get;
	string str;

	ifstream fs(".\\text\\" + getstr);
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
	}
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    char* get = getenv("QUERY_STRING");
	string getstr = get;
	string str;
	int pos = 0;
	int strpos = 0;
	int i = 0;
	char chs[2] = { 0 };
	char* p = nullptr;
	char ret = 0;

	if (getstr.find("%") != getstr.npos)
	{
		while ((pos = getstr.find("%", pos)) != string::npos)
		{
			if (i == 1)
			{
				chs[0] = strpos + 1;
				chs[1] = pos - 1;
				ret = strtol(chs, &p, 16);
				getstr.erase(strpos,3);
				getstr[strpos] = ret;
				i = 0;
			}
			else
			{
				strpos = pos;
				i++;
			}
			pos++;
		}
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
	}
}
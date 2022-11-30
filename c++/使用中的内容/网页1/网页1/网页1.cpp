#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;
int main() {
	int listlen = 0;
	int len = atoi(getenv("CONTENT_LENGTH"));
	char* get = getenv("QUERY_STRING");
	char* charstr[1000] = { 0 };
	string str;
	char* post = new char[len + 1];
	{
		int tmp = 0;
		while (tmp < (len))
		{
			post[tmp] = fgetc(stdin);
			tmp++;
		}
		post[tmp] = '\0';
		/*int n = 0;
		for (size_t i = 0; i < strlen(post); i++)
		{
			if (post[i] != ' ' && post[i] != 0)
			{
				n = 1;
				break;
			}
		}
		if (n == 1) {
			cout << "Content-type:text/html\r\n\r\n";
			cout << "<html>\n";
			cout << "<head>\n";
			cout << "<title>QWQ</title>\n";
			cout << "</head>\n";
			cout << "<body>\n";
			cout << "<p>名称为空</p>\n";
			cout << "</body>\n";
			cout << "</html>\n";
			return 0;
		}
		*/
	}
//	codecvt_utf8<wchar_t> code();
//	code;
	string filename = get,title = "未找到配置文件";
	fstream fs(filename, ios::in),fscfg(filename+".cfg", ios::in);
	cout << "Content-type:text/html\r\n\r\n";
	cout << "<html>\n";
	cout << "<head>\n";
	cout << "<meta http - equiv = \"Cache-Control\" content = \"no-cache, no-store, must-revalidate\" / >\n";
	cout << "<meta http - equiv = \"Pragma\" content = \"no-cache\" / >\n";
	cout << "<meta http - equiv = \"Expires\" content = \"0\" / >\n";
	cout << "<title>QWQ</title>\n";
	cout << "</head>\n";
	cout << "<body>\n";
	if (!fs) {
		cout << "<p>文件不存在</p>\n";
		cout << "<p>请求的文件名为" << get << "</p>";
		cout << "</body>\n";
		cout << "</html>\n";
		return 0;
	}
	if (fscfg) {
		fscfg >> title;
	}
	cout << "<p>" << title << "</p>" << endl;
	//fs.unsetf(ios::skipws);
	cout << "<div style=\"margin:0 20% 0 20%;\">\n";
	while (fs.peek() != EOF)
	{
		getline(fs, str);
		//fs >> str;
		cout << "<p>" << str << "</p>\n";	
	}
	cout << "</div>\n";
	cout << "</body>\n";
	cout << "</html>\n";
	return 0;
}
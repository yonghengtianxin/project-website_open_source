#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>
using namespace std;
int main() {
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
	}
	string getstr = get;
	
	string background_image_src;
	vector<string> strvc;
	srand(time(NULL));
	ifstream fs(".\\img\\imglist", ios::in);
	if (fs)
	{
		while (fs.peek() != EOF)
		{
			getline(fs, str);
			strvc.push_back(str);
		}
	}
	
	cout << "Content-type:text/html;\r\n\r\n";
	cout << "<html lang=zh-CN>\n";
	cout << "<head>\n";
	cout << "<meta charset=\"GB18030\">\n";
	cout << "<meta name=\"viewport\" content=\"initial-scale=1, maximum-scale=1\">\n";
//	cout << "<meta charset=\"utf-8\">\n";
	cout << "<meta http-equiv=\"Cache-Control\" content = \"no-cache,no-store,must-revalidate\" / >\n";
	cout << "<meta http-equiv=\"Pragma\" content=\"no-cache\" / >\n";
	cout << "<meta http-equiv=\"Expires\" content=\"0\" / >\n";
	int backgroundimagecode = rand() % strvc.size();
	string backgroundimagename = strvc[backgroundimagecode];
	if (strvc.size() > 0)
	{
		cout << "<style>body{background-image: url(\"./img/" << strvc[backgroundimagecode] << "\");}</style>\n";

	}
	cout << "<link rel=\"stylesheet\"type=\"text/css\"href=\"./css/base.css\">\n";
	cout << "<title>前端测试页面</title>\n";
	cout << "<script src=\"/js/changepage.js\"></script>\n";
	if (getstr != "")
	{
		if (getstr == "game")
		{
			cout << "<script>window.history.pushState(\"" + getstr + "\",null,\"" + getstr + "\");document.title=\"" + getstr + "\";</script>\n";
			//cout << "<script>onclick=gotogamepage()</script>\n";
		}
		else if (getstr == "bloglist") {
			cout << "<script>window.history.pushState(\"" + getstr + "\",null,\"" + getstr + "\");document.title=\"" + getstr + "\";</script>\n";
			cout << "<script>gotobloglist()</script>\n";
		}
		else {
			cout << "<script>window.history.pushState(\"" + getstr + "\",null,\"blogs/" + getstr + "\");document.title=\"" + getstr + "\";</script>\n";
			cout << "<script src=\"/js/ajax.js\" defer ></script>\n";
		}
	}
	else
	{
		cout << "<script defer>window.history.pushState(null,null,\"blogs\");</script>\n";
	}
//	cout << "<script defer>document.getElementById(\"index\").addEventListener(\"click\", changepage(\"index\"));</script>\n";
	cout << "</head>\n";
	cout << "<body>\n";
	cout << "<div class=\"base\">\n";
//	cout << "<iframe src=\"/网页2.exe\" allow=\"autoplay\">\n";
	cout << "<div id='audioPay'></div>\n";
	cout << "<div class=nav>\n";

//	cout << "<div class=nav_left id=index><a>首页</a></div>\n";
	cout << "<button class=nav_left onclick=gotoindex(\""+ getstr + "\")><a>首页</a></button>\n";
	cout << "<button class=nav_left onclick=gotobloglist()><a>博客</a></button>\n";
	cout << "<button class=nav_left><a>小说</a></button>\n";
	cout << "<button class=nav_left onclick=gotogamepage()><a>游戏</a></button>\n";
	cout << "<button class=nav_right><a>关于天心</a></button>\n";

	cout<< "</div>\n";

	cout << "<span id=\"main\">\n";
	


	cout << "<div class=\"biaoti\">基础内容</div>\n";
	cout << "<div class=\"zhengwen\">\n";
	cout << "&nbsp;&nbsp;基本内容\n";
	cout << get << "\n";
	cout << "</div>\n";

	cout << "</span>\n";

	cout << "<div class=\"foot\">\n";
	cout << "<div>背景图片:" + backgroundimagename + "</div>\n";
	cout << "<div>联系天心yonghengtianxin@gmail.com</div>\n";
	cout << "<div>by永恒·天心 2022</div></div>\n";

	cout << "<audio name=\"media\" loop=\"\" controls id=music class=\"music\"> <source src=\"/audio/ZUN - 今宵は飄逸なエゴイスト (Live ver) ~ Egoistic Flowers.mp3\" type=\"audio/mpeg\"></audio>\n";

	cout << "</div>\n";

	cout << "<form action = \"./api/comment.exe\" method = \"POST\" enctype=\"GB18030\" class=\"comment\">\n";
	cout << "<p style=\"padding-right:20px\">这里是评论区哦</p>\n";
	cout << "<input type=\"text\" name=\"评论\">\n";
	cout << "<input type=\"submit\" value=\"提交\">\n";
	cout << "</form>\n";

	cout << "<script src=\"/js/base.js\" defer ></script>\n";
	cout << "</body>\n";
	cout << "</html>\n";
	return 0;
}
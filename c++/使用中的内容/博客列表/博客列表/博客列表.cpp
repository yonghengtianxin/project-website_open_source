#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std::filesystem;
using namespace std;

int main() {
    string path = std::filesystem::current_path().string() + "/text";
    string str;
    system("cd ..");
    cout << "Content-type:text/html;charset=GB18030\r\n\r\n";
    cout << "<p class=\"biaoti\">这里是博客列表的说~<p>" << endl;
    for (const auto& file : directory_iterator(path)) {
        cout << "<button class=\"button\" class=\"zhengwen\" onclick=gotopage(\"" + file.path().string().substr(file.path().string().rfind("\\") + 1, file.path().string().length()) + "\")>" << file.path().string().substr(file.path().string().rfind("\\") + 1, file.path().string().length()) << "</button>" << endl;
        cout << "<br>" << endl;
    }
    return EXIT_SUCCESS;
}

/*int main()
{
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

}
*/
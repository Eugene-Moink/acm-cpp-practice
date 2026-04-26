#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    getline(cin, text);

    int n = text.length(); // 获取字符串长度，作为循环的上限

    // 请在此处编写 for 循环，遍历并输出每个字符
    for(int i = 0; i < n; i++)
    {
        cout << text[i] << endl;
    }


    return 0;
}
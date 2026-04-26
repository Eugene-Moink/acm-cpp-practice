#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string text;
    getline(cin, text); // 读取整行

    // 请在此处获取字符串的长度
    // int len = ... ;
    int len_num = text.size();

    cout << len_num << endl;

    return 0;
}
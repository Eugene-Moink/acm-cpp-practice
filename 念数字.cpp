#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 定义一个数组，将数字 0-9 映射到对应的拼音
    // pinyin[0] = "ling", pinyin[1] = "yi", ...
    string pinyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    
    string num_str;
    cin >> num_str; // 直接以字符串形式读入，方便处理符号和每一位

    // 用于控制输出空格的标志
    bool is_first = true;

    // 遍历字符串中的每一个字符
    for (int i = 0; i < num_str.length(); ++i) 
    {
        char c = num_str[i];
        
        // 如果是负号，输出 "fu"
        if (c == '-') 
        {
            cout << "fu";
            is_first = false; // 负号也算第一个输出的部分
            continue; // 跳过本次循环，继续处理下一个字符
        }

        // 将字符转换为整数
        int digit = c - '0';

        // 输出空格（如果这不是第一个要输出的拼音）
        if (!is_first) 
        {
            cout << " ";
        }
        is_first = false;

        // 输出对应的拼音
        cout << pinyin[digit];
    }

    // 最后输出一个换行符
    cout << endl;

    return 0;
}
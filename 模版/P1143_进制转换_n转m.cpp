#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* =====================================================
进制转换通用模板

【用途】
  支持将任意进制（2~36进制）的字符串转换为十进制长整型，
  以及将十进制长整型转换回任意进制的字符串。
  常用于处理“进制转换”、“大整数读入输出”等题型的子问题。

【字符映射规则】
  0-9 对应 0-9，A-Z 对应 10-35，a-z 对应 10-35（不区分大小写）。

【参数】
  charToInt(c): 字符转数值，非法字符返回 -1。
  intToChar(d): 数值转字符，返回大写字母（如 10 -> 'A'）。
  parseBase(num, base): 将字符串 num 从 base 进制解析为十进制值（返回 ll）。
  toBase(num, base): 将十进制整数 num 转换为 base 进制的字符串（返回 string）。

【复杂度】
  时间复杂度 O(L)（L为字符串长度），空间复杂度 O(L)。

【易错提醒】
  1. 输入字符串若为 "0"，转换后的字符串也为 "0"。
  2. 仅支持非负整数，处理负数需自行加符号逻辑。
  3. 如果数据范围超过 2^63-1（即 ll 上限），需改用大数模板（如 Python 或高精度算法）。
===================================================== */

// 字符转数值
int charToInt(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 10;
    if ('a' <= c && c <= 'z')
        return c - 'a' + 10;
    return -1;
}

// 数值转字符（统一输出大写）
char intToChar(int d)
{
    if (d < 10)
        return '0' + d;
    return 'A' + (d - 10);
}

// 任意进制字符串 -> 十进制整数
ll parseBase(const string &num, int base)
{
    ll res = 0;
    for (char c : num)
    {
        int d = charToInt(c);
        if (d < 0 || d >= base)
            return -1; // 非法数字
        res = res * base + d;
    }
    return res;
}

// 十进制整数 -> 任意进制字符串
string toBase(ll num, int base)
{
    if (num == 0)
        return "0";
    string out;
    while (num > 0)
    {
        out.push_back(intToChar(num % base));
        num /= base;
    }
    reverse(out.begin(), out.end());
    return out;
}

/* ==================== 调用示例（原题逻辑） ==================== */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    string num;
    cin >> n >> num; // 源进制 n，数字字符串 num
    cin >> m;        // 目标进制 m

    ll temp = parseBase(num, (int)n);
    if (temp == -1)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    cout << toBase(temp, (int)m) << endl;

    return 0;
}
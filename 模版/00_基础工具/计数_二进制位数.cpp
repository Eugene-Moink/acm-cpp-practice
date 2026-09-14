#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 功能：计算正整数 n 的二进制表示所占的位数
// 参数：n（大于 0 的整数）
// 返回值：n 的二进制位数（例如 n=5 (101) → 3；n=8 (1000) → 4）
// 原理：不断右移，每次移一位计数器加 1，直到 n 变为 0
int bit_length(ll n)
{
    int len = 0;
    while (n > 0)
    {
        len++;
        n >>= 1; // 等价于 n /= 2，但位运算更快
    }
    return len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    cout << bit_length(n) << '\n';
    return 0;
}
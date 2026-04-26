#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;

    int books_count = m / 13;  // 计算可以买的本数
    int remaining_money = m % 13; // 计算剩余的钱

    cout << books_count << endl;   // 输出本数
    cout << remaining_money << endl; // 输出剩余金额

    return 0;
}
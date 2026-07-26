#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;

    // 1. 从小到大尝试因子 i
    // 使用 i <= n / i 而不是 i * i <= n，从根本上防止 i*i 溢出 long long
    for (ll i = 2; i <= n / i; i++)
    {
        // 2. 只要 n 能被 i 整除，i 就是一个质因子
        // 使用 while 是为了把相同的质因子全部除尽（例如 12 里面有 2 个 2）
        while (n % i == 0)
        {
            cout << i << endl; // 根据题目要求，每行输出一个质因子
            n /= i;            // 除掉这个因子，n 变小
        }
    }

    // 3. 如果除掉所有小因子后，剩下的 n 仍大于 1，说明它本身是一个大质数
    if (n > 1)
    {
        cout << n << endl;
    }
}

int main()
{
    // 竞赛标配 IO 加速器
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
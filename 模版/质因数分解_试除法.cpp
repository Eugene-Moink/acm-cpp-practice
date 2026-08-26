#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* =====================================================
质因数分解模板（试除法）

【用途】
  对一个正整数 n 进行质因数分解，返回它所有的质因子（包含重复项）。
  例如输入 12，返回 [2, 2, 3]；输入 13，返回 [13]。

【参数】
  n (ll): 待分解的整数（要求 n >= 2）。

【返回值】
  vector<ll>: 按升序排列的所有质因子。

【算法原理】
  从小到大枚举因子 i，只要 n 能被 i 整除，就持续除掉 i。
  除尽后，若剩余 n > 1，则剩余的部分一定是一个大于 sqrt(原n) 的大质数。

【复杂度】
  时间复杂度 O(sqrt(n))，空间复杂度 O(质因子个数)。

【防溢出关键点】
  循环条件使用 i <= n / i 而非 i * i <= n，防止 i*i 溢出 long long。
===================================================== */
vector<ll> get_prime_factors(ll n)
{
    vector<ll> factors;
    for (ll i = 2; i <= n / i; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }
    return factors;
}

/* ==================== 调用示例 ==================== */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> ans = get_prime_factors(n);

    // 按原题要求，每行输出一个质因子
    for (ll x : ans)
    {
        cout << x << "\n";
    }

    return 0;
}
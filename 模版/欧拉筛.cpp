#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* =====================================================
欧拉筛（线性筛）模板

【用途】
  在 O(n) 的时间复杂度内，筛出 [2, n] 范围内的所有素数。
  常用于“查询第 k 个素数”、“快速判断 1e7 内的数是否为素数”等题目。
  相比埃氏筛（O(n log log n)），欧拉筛让每个合数只会被它的最小质因子筛掉一次，彻底避免重复标记，因此速度极快，不会 TLE。

【参数】
  n (int): 筛的上限。

【全局变量（函数外部声明）】
  is_prime (vector<bool>): 标记是否为素数。
  prime (vector<int>):     按顺序存储筛出的所有素数。

【返回值】
  无，直接修改全局数组。

【复杂度】
  时间复杂度 O(n)，空间复杂度 O(n)。

【防溢出关键点】
  循环条件中必须写 1LL * i * prime[j] <= n，否则当 n 较大时 i * prime[j] 会溢出 int，导致死循环或越界。
===================================================== */
vector<bool> is_prime;
vector<int> prime;

void sieve(int n)
{
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime.push_back(i);

        for (int j = 0; j < prime.size() && 1LL * i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break; // 核心：保证每个合数只被最小质因子筛掉一次
        }
    }
}

/* ==================== 调用示例 ==================== */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    sieve(n);

    while (q--)
    {
        int k;
        cin >> k;
        cout << prime[k - 1] << "\n"; // 下标从0开始，所以是 k-1
    }

    return 0;
}
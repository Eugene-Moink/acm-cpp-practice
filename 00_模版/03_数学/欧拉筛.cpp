/*
 * 欧拉筛（线性筛）
 *
 * 输入：n (int)，筛出 [2, n] 内所有素数
 * 全局：is_prime[], prime[] 分别保存素性标记与素数表
 * 复杂度：O(n)
 *
 * 防溢出：循环条件必须写 1LL * i * prime[j] <= n
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> is_prime;
vector<int> prime;

void sieve(int n)
{
  is_prime.assign(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  prime.clear();

  for (int i = 2; i <= n; i++)
  {
    if (is_prime[i])
      prime.push_back(i);

    for (int j = 0; j < (int)prime.size() && 1LL * i * prime[j] <= n; j++)
    {
      is_prime[i * prime[j]] = false;
      if (i % prime[j] == 0)
        break;
    }
  }
}

void solve()
{
  int n, q;
  if (!(cin >> n >> q))
    return;

  sieve(n);

  while (q--)
  {
    int k;
    cin >> k;
    cout << prime[k - 1] << "\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  // cin >> T;
  while (T--)
  {
    solve();
  }

  return 0;
}
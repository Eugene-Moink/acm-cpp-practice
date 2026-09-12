/*
 * =====================================================
 * 快速幂模板（模运算）
 * =====================================================
 *
 * 【用途】
 * 计算 base 的 exp 次幂对 mod 取模的结果（即 base^exp % mod）。
 * 常用于处理指数极大（如 1e18）的情况，防止直接乘方溢出和超时，
 * 是数论、组合数学题中的核心工具。
 *
 * 【参数】
 * base (ll): 底数
 * exp  (ll): 指数（可以为 0）
 * mod  (ll): 模数（建议 >= 1，若为 1，则任何数的结果都是 0）
 *
 * 【返回值】
 * ll: 运算结果
 *
 * 【算法原理】
 * 二进制拆分指数。将 exp 拆成二进制，例如 13 = 8 + 4 + 1。
 * 计算 base^1, base^2, base^4, base^8...，然后根据 exp 的二进制位
 * 决定是否乘入结果。
 *
 * 【复杂度】
 * 时间复杂度 O(log exp)，空间复杂度 O(1)。
 *
 * 【防溢出关键点】
 * 乘法运算时，强制使用 (res * base) % mod，且提前使用 `base %= mod`
 * 缩小数值范围。
 *
 * 【如何适配多组测试数据】
 * 默认只跑 1 组数据。如果题目输入文件含多组独立的测试用例
 * （例如第一行给定总组数 T），把 main() 函数中 // cin >> T;
 * 前面的注释去掉即可。
 * =====================================================
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll qpow(ll base, ll exp, ll mod)
{
  ll res = 1 % mod;
  base %= mod;
  while (exp > 0)
  {
    if (exp & 1)
    {
      res = (res * base) % mod;
    }
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}

void solve()
{
  ll a, b, p;
  if (!(cin >> a >> b >> p))
    return;

  ll result = qpow(a, b, p);
  cout << a << "^" << b << " mod " << p << "=" << result << "\n";
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
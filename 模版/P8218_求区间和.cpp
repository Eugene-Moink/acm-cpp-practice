/*
 * =====================================================
 * 前缀和模板（静态区间和查询）
 * =====================================================
 *
 * 【用途】
 * 给定一个静态数组，快速回答大量形如 "求区间 [l, r] 的和" 的查询。
 * 如果在多次查询中数组元素不会改变，这是一种非常高效的方法。
 *
 * 【参数】
 * a (vector<ll>): 原始数组，建议使用 1-based 索引（a[0] 为 0，占位）。
 *                 传入时直接使用 build_prefix_sum(a)。
 *
 * 【返回值】
 * vector<ll>: 前缀和数组 prefix。
 *             prefix[i] 表示 a[1] + a[2] + ... + a[i] 的总和。
 *
 * 【核心查询公式】
 * 区间 [l, r] 的和 = prefix[r] - prefix[l - 1]
 *
 * 【复杂度】
 * 预处理时间 O(N)，单次查询时间 O(1)，空间复杂度 O(N)。
 *
 * 【易错提醒】
 * prefix[0] 必须严格初始化为 0。
 * 所有涉及到求和的变量（如 a 和 prefix）建议使用 long long，防止累加时溢出 int。
 *
 * 【如何适配多组测试数据】
 * 默认只跑 1 组数据（内部处理一个 n 和对应的 q 次查询）。
 * 如果题目输入文件含多组独立的测试用例（例如第一行给定总组数 T），
 * 把 main() 函数中 // cin >> T; 前面的注释去掉即可。
 * =====================================================
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> build_prefix_sum(const vector<ll> &a)
{
  int n = a.size() - 1;
  vector<ll> prefix(n + 1, 0);
  for (int i = 1; i <= n; ++i)
  {
    prefix[i] = prefix[i - 1] + a[i];
  }
  return prefix;
}

ll query_range_sum(const vector<ll> &prefix, int l, int r)
{
  return prefix[r] - prefix[l - 1];
}

void solve()
{
  int n;
  if (!(cin >> n))
    return;

  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i];
  }

  vector<ll> pref = build_prefix_sum(a);

  int q;
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << query_range_sum(pref, l, r) << "\n";
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
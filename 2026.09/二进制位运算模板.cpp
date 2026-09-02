#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* =====================================================
二进制位运算模板（GCC内置函数版）

【用途】
  处理关于二进制表示的高效查询问题，例如：
  1. 统计一个超长整数（long long）二进制中 1 的个数。
  2. 找二进制中最右侧的 1 的位置（最小编号）。
  3. 找二进制中最左侧的 1 的位置（最大编号）。

【参数】
  x (ll): 需要查询的非负整数。

【函数说明】
  __builtin_popcountll(x): 统计二进制中 1 的个数。（注意必须加 ll，处理 long long）
  __builtin_ctzll(x):     统计末尾连续 0 的个数。（即最低位 1 的索引/最小编号）
  __builtin_clzll(x):     统计前导连续 0 的个数。

【最大值计算公式】
  最大编号 = 63 - __builtin_clzll(x)。
  因为 ll 是64位，前导0的个数+1就是最高位1的索引。

【易错点与特殊边界】
  1. 必须用 long long，且函数后缀必须是 ll，否则 int 会溢出或算错。
  2. 如果 x == 0，ctzll 和 clzll 的行为是未定义的（会报错/随机数），必须特判！
  3. 如果题目要求输出数值（如最低位1的值），用 x & -x；如果要求输出下标，用 __builtin_ctzll。
===================================================== */

void solve()
{
    ll x;
    cin >> x;

    // 特判边界：0无激活通道
    if (x == 0)
    {
        cout << "0 -1 -1" << '\n';
        return;
    }

    // 1. 统计 1 的个数
    ll one = __builtin_popcountll(x);

    // 2. 最小编号（二进制末尾 0 的个数）
    ll min_one = __builtin_ctzll(x);

    // 3. 最大编号（64 减去前导 0 的个数，再减 1）
    ll max_one = 63 - __builtin_clzll(x);

    cout << one << " " << min_one << " " << max_one << '\n';
}

/* ==================== 调用示例 ==================== */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
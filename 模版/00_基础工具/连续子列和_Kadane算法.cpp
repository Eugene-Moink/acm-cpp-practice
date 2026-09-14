/*
 * 最大连续子段和（Kadane 算法）
 *
 * 输入：vector<ll>& a
 * 输出：非空连续子段的最大和（全负数时返回最大的负数）
 * 复杂度：O(N) 时间，O(1) 空间
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll max_subarray_sum(const vector<ll> &a)
{
    ll cur = 0;
    ll best = LLONG_MIN;

    for (ll x : a)
    {
        cur += x;
        if (cur > best)
        {
            best = cur;
        }
        if (cur < 0)
        {
            cur = 0;
        }
    }
    return best;
}

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << max_subarray_sum(a) << "\n";
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
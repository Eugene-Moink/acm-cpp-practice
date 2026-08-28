#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 最大连续子段和（Kadane算法）
// 要求：子段严格非空；全负数时，返回最大的那个负数
// 复杂度：O(N)时间，O(1)空间
// 用途：求一个一维数组中，非空的连续子段的最大和（经典的最大子段和问题）。常用于处理股票买卖收益、连续区间最值等题型。
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

// 使用示例：
// int n; cin >> n;
// vector<ll> a(n);
// for (int i = 0; i < n; i++) cin >> a[i];
// cout << max_subarray_sum(a) << '\n';
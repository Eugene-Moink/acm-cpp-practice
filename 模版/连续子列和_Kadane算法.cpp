#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 最大连续子段和（Kadane算法）
// 要求：子段严格非空；全负数时，返回最大的那个负数
// 复杂度：O(N)时间，O(1)空间
ll max_subarray_sum(const vector<ll> &a)
{
    ll cur = 0;
    ll best = LLONG_MIN; // 初始化为极小值，防止全负数出错

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
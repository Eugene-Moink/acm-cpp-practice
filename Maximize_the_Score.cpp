#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> a, pos;
vector<vector<ll>> dp;

ll dfs(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    if (l == r)
    {
        return 1;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }

    ll res = 0;

    int m = pos[l];
    if (m > l && m <= r)
    {
        ll len = m - l + 1;
        res = max(res, len * len + dfs(m + 1, r));
    }
    else
    {
        res = max(res, 1 + dfs(l + 1, r));
    }

    for (int k = l; k < r; ++k)
    {
        res = max(res, dfs(l, k) + dfs(k + 1, r));
    }

    return dp[l][r] = res;
}

void solve()
{
    int n;
    cin >> n;
    a.resize(2 * n + 1);
    pos.resize(2 * n + 1);
    vector<int> first(n + 1, -1);

    for (int i = 1; i <= 2 * n; ++i)
    {
        cin >> a[i];
        if (first[a[i]] == -1)
        {
            first[a[i]] = i;
        }
        else
        {
            int p = first[a[i]];
            pos[i] = p;
            pos[p] = i;
        }
    }

    dp.assign(2 * n + 1, vector<ll>(2 * n + 1, -1));
    cout << dfs(1, 2 * n) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
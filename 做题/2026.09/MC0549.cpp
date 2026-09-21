#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    int min_val = INT_MAX;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        min_val = min(min_val, x);
    }

    vector<int> diff(n + 2, 0);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l = max(1, l - min_val + 1);
        r = min(n, r - min_val + 1);

        if (l <= r)
        {
            diff[l] += 1;
            diff[r + 1] -= 1;
        }
    }

    ll cur = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += diff[i];
        ans += cur;
    }

    ll result = (1LL * n * m - ans) % 10007;
    cout << result << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (ll &val : a)
    {
        cin >> val;
        sum += val;
    }

    int len = k - 1;
    if (len == 0)
    {
        cout << sum << '\n';
        return;
    }

    ll cur = 0, min_sum = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        cur += a[i];
        if (i >= len)
            cur -= a[i - len];
        if (i >= len - 1)
            min_sum = min(min_sum, cur);
    }

    cout << sum - min_sum << '\n';
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
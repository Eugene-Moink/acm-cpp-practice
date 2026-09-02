#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll target = t + pref[i - 1];
        int idx = upper_bound(pref.begin(), pref.end(), target) - pref.begin();
        int cur = idx - i;

        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
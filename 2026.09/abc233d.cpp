#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    ll ans = 0;
    map<ll, int> cnt;
    cnt[0] = 1;
    for (int r = 1; r <= n; r++)
    {
        ans += cnt[pref[r] - k];
        cnt[pref[r]]++;
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
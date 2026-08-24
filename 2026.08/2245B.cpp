#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    ll ans = LLONG_MIN;
    int start_ops = (n + 1) / 2;

    for (int ops = start_ops; ops <= n; ++ops)
    {
        ll cur = pref[ops] - (ll)ops * c;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
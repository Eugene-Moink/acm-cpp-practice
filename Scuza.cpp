#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    vector<ll> mx;
    ll val_max = a[1];
    for (int i = 1; i <= n;i++)
    {
        ll cur = a[i];
        val_max = max(cur, val_max);
        mx.push_back(val_max);
    }

    while(q--)
    {
        ll k;
        cin >> k;
        int ans_idx = upper_bound(mx.begin(), mx.end(), k) - mx.begin();
        ll ans = pref[ans_idx];
        cout << ans << ' ';
    }
    cout << '\n';
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
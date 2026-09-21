#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int m, q, b;
    cin >> m >> q >> b;
    vector<ll> a(m);
    for (ll &x : a)
    {
        cin >> x;
    }

    vector<ll> pref(m + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    while (q--)
    {
        ll p;
        cin >> p;
        int idx = lower_bound(pref.begin(), pref.end(), p) - pref.begin();
        ll pos = p - pref[idx - 1];
        int state = (idx % 2 == 1) ? b : 1 - b;
        cout << state << " " << idx << " " << pos << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
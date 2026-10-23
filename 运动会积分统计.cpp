#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
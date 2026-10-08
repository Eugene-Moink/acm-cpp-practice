#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    unordered_map<ll, vector<int>> group;
    for (int x = 0; x < n - 4; x++)
    {
        ll v = a[x] + a[x + 2] - a[x + 4];
        group[v].push_back(x);
    }

    ll ans = 0;
    for (auto &[v, pos] : group)
    {
        ll k = pos.size();
        unordered_set<int> s(pos.begin(), pos.end());
        ll cnt = k * (k - 1) / 2;
        ll cnt2 = 0, cnt4 = 0;
        for (int x : pos)
        {
            if (s.count(x + 2))
                cnt2++;
            if (s.count(x + 4))
                cnt4++;
        }
        cnt -= (cnt2 + cnt4);
        ans += cnt;
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
        solve();
    }
    return 0;
}
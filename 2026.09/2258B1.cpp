#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    set<int> cand;
    for (int x : a)
    {
        cand.insert(x);
        if (x % 2 == 0)
        {
            cand.insert(x / 2);
        }
    }

    vector<int> cnt(m + 1, 0);
    for (int x : a)
    {
        cnt[x]++;
    }

    vector<int> suf(m + 2, 0);
    for (int i = m; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + cnt[i];
    }

    ll ans = 0;
    for (int x : cand)
    {
        ll cur = cnt[x];
        if (x + 1 <= m)
            cur += suf[x + 1];
        if (2 * x <= m)
            cur += cnt[2 * x];

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
        solve();
    }
    return 0;
}
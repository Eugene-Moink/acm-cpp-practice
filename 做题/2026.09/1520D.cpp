#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x - i;
    }

    map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        cnt[a[i]]++;
    }

    ll ans = 0;
    for (auto &p : cnt)
    {
        ll val = p.second;
        ans += (val - 1) * val / 2;
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);

    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    vector<ll> pref_a(n + 1, 0), pref_b(m + 1, 0);
    for (int i = 1; i <= n; i++)
        pref_a[i] = pref_a[i - 1] + a[i - 1];
    for (int i = 1; i <= m; i++)
        pref_b[i] = pref_b[i - 1] + b[i - 1];

    int ans = 0;
    int cnt = m;
    for (int i = 0; i <= n; i++)
    {
        ll remain = k - pref_a[i];
        if (remain < 0)
        {
            break;
        }

        while (cnt > 0 && remain < pref_b[cnt])
        {
            cnt--;
        }
        ans = max(ans, i + cnt);
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
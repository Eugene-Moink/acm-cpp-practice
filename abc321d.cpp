#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(b.begin(), b.end());

    vector<ll> pref(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        pref[i + 1] = pref[i] + b[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(b.begin(), b.end(), p - a[i]) - b.begin();
        ans += 1LL * idx * a[i] + pref[idx];
        ans += 1LL * (m - idx) * p;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
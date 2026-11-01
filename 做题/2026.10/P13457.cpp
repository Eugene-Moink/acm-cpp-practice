#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int m;
        cin >> m;

        vector<ll> a(m), b(m);

        for (int j = 0; j < m; j++)
            cin >> a[j];
        for (int j = 0; j < m; j++)
            cin >> b[j];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        ll ans = 0;
        for (int j = 0; j < m; j++)
            ans += a[j] * b[j];

        cout << "Case #" << i << ": " << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    vector<vector<ll>> col_pref(n + 1, vector<ll>(m + 1, 0));
    for (int j = 1; j <= m; ++j)
        for (int i = 1; i <= n; ++i)
            col_pref[i][j] = col_pref[i - 1][j] + a[i][j];

    ll ans = 0;

    for (int top = 1; top <= n; ++top)
    {
        for (int bottom = top; bottom <= n; ++bottom)
        {

            vector<ll> col_sum(m + 1);
            for (int j = 1; j <= m; ++j)
            {
                col_sum[j] = col_pref[bottom][j] - col_pref[top - 1][j];
            }

            int l = 1;
            ll sum = 0;
            for (int r = 1; r <= m; ++r)
            {
                sum += col_sum[r];

                while (sum > k && l <= r)
                {
                    sum -= col_sum[l];
                    l++;
                }

                ans += (r - l + 1);
            }
        }
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, s;
    ll l;
    cin >> n >> s >> l;
    vector<ll> a(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];

    vector<ll> pref(n + 1, 0);
    pref[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 2];
    }

    ll limit = l;
    ll ans = 1;

    for (int L = 1; L <= s; L++)
    {
        for (int R = s; R <= n; R++)
        {
            ll full = pref[R] - pref[L];
            ll toLeft = pref[s] - pref[L];
            ll toRight = pref[R] - pref[s];
            ll dist = full + min(toLeft, toRight);
            if (dist <= limit)
            {
                ans = max(ans, (ll)(R - L + 1));
            }
        }
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (ll &x : a)
        cin >> x;
    for (ll &x : b)
        cin >> x;

    auto check = [&](ll mid) -> bool
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll tmp = a[i] * mid;
            if (tmp > b[i])
            {
                sum += tmp - b[i];
            }

            if (sum > k)
                return false;
        }

        return true;
    };

    ll l = 0, r = 2e9;
    ll ans = 0;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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
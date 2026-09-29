#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> a;
ll n, h;

bool check(ll x)
{
    ll sum = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        sum += min(x, a[i + 1] - a[i]);
        if (sum >= h)
            return true;
    }
    sum += x;
    return sum >= h;
}

void solve()
{
    cin >> n >> h;
    a.resize(n);
    for (ll &x : a)
        cin >> x;

    ll lo = 1, hi = (ll)1e18;
    ll ans = h;

    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
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
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll mid, const vector<ll> &a, ll x)
{
    ll sum = 0;
    for (ll c : a)
    {
        if (c < mid)
            sum += max(0LL, mid - c);
    }

    if (sum <= x)
        return true;

    return false;
}

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    ll lo = 1;
    ll hi = *max_element(a.begin(), a.end()) + x;
    while (lo < hi)
    {
        ll mid = lo + (hi - lo + 1) / 2;
        if (check(mid, a, x))
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo << '\n';
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
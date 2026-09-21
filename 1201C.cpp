#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll x, vector<ll> &a, ll k)
{
    int n = a.size();
    int mid = n / 2;
    ll cost = 0;

    for (int i = mid; i < n; i++)
    {
        if (a[i] < x)
        {
            cost += x - a[i];
            if (cost > k)
                return false;
        }
    }
    return cost <= k;
}

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a)
    {
        cin >> x;
    }

    sort(a.begin(), a.end());
    int mid = n / 2;
    ll lo = a[mid];
    ll hi = a[mid] + k;
    while (lo < hi)
    {
        ll mid_val = lo + (hi - lo + 1) / 2;
        if (check(mid_val, a, k))
            lo = mid_val;

        else
            hi = mid_val - 1;
    }
    cout << lo << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
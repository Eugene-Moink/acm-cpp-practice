#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll k, vector<ll> &a)
{
    int n = a.size();
    ll cur = -4e12;

    for (int i = 0; i < n; i++)
    {
        ll L = a[i] - k;
        ll R = a[i] + k;

        cur = max(cur, L);
        if (cur > R)
            return false;
        cur++;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    ll low = 0, high = 1LL << 40;
    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, a))
            high = mid;
        else
            low = mid + 1;
    }
    cout << low << '\n';
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<ll> &a, ll mid, int m)
{
    int cnt = 1, cur = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {

        if (cur + a[i] <= mid)
        {
            cur += a[i];
        }
        else
        {
            cnt++;
            cur = a[i];
        }
    }
    return cnt <= m;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll lo = 0, hi = 0;
    for (ll &x : a)
    {
        cin >> x;
        lo = max(lo, x);
        hi += x;
    }

    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(a, mid, m))
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

    solve();
    return 0;
}
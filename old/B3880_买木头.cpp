#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll n,m;
vector<ll> l, s;

bool check(ll mid)
{
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        cnt += (l[i] / mid) * s[i];
        if (cnt >= m)
        {
            return 1;
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    l.resize(n);
    s.resize(n);
    cin >> l[0] >> s[0];

    for (ll i = 1; i < n;i++)
    {
        l[i] = (((l[i-1] * 37011 + 10193)) % 10000) + 1;
        s[i] = (((s[i-1] * 73011 + 24793)) % 100) + 1;
    }

    ll max_len = 0;
    for (ll i = 0; i < n;i++)
    {
        max_len = max(max_len, l[i]);
    }

    ll left = 1, right = max_len, ans = 0;
    while (left <= right)
    {

        ll mid = left + (right - left) / 2;
        if(check(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
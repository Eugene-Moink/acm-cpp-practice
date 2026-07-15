#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll n, m;
ll max_h = -1;
vector<ll> high;

bool cheak(ll mid)
{
    ll total = 0;
    for (ll i = 0; i < n;i++)
    {
        if(high[i]>mid)
        {
            total += high[i] - mid;
        }
    }
    return total >= m;
}

void solve()
{
    
    cin >> n >> m;
    high.resize(n);
    
    for (ll i = 0; i < n;i++)
    {
        cin >> high[i];
        max_h = max(max_h, high[i]);
    }

    ll l = 0;
    ll r = max_h;
    ll ans = 0;

    while(l<=r)
    {
        ll mid = l + (r - l) / 2;

        if(cheak(mid))
        {
            ans = mid;
            l = mid + 1;
        }

        else
        {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
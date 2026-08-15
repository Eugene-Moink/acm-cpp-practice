#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll n, k;
vector<ll> h, w;

bool check(ll mid) 
{
    ll cnt = 0;
    for (int i = 0; i < n; i++) 
    {
        cnt += (h[i] / mid) * (w[i] / mid);
    }
    return cnt >= k;
}

void solve()
{
    
    cin >> n >> k;
    h.resize(n); w.resize(n);
    ll max_side = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> h[i] >> w[i];
        max_side = max(max_side, max(h[i], w[i])); // 记录所有尺寸中的最大值
    }

    ll l = 1;
    ll r = max_side;
    ll ans = 0;

    while(l<=r)
    {
        ll mid = l + (r - l) / 2;

        if(check(mid))
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
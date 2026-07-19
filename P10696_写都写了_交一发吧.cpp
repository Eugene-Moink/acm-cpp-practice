#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> g(n);
    for (ll i = 0; i < n; i++) cin >> g[i];

    ll ans = 0;
    for (ll bit = 29; bit >= 0; bit--)
    {
        ll candidate = ans | (1LL << bit);
        ll cnt = 0;
        
        for (ll i = 0; i < n; i++)
        {
            if ( (g[i] & candidate) == candidate )
            {
                cnt++;
                if (cnt >= 1) break; 
            }
        }
        
        if (cnt >= 1) ans = candidate;
    }
    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
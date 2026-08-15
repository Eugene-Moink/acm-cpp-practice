#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    ll len = 0;
    for (ll i = 0; i < n;i++)
    {
        if(s[i] == '#')
        {
            len++;
        }

        else
        {
            if (len > 0)
            {
                ll cur_time = (len + 1) / 2;
                ans = max(ans, cur_time);
            }
            len = 0;
        }
    }

    
    if (len > 0)
    {
        ll cur_time = (len + 1) / 2;
        ans = max(ans, cur_time);
    }
    len = 0;
        
    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
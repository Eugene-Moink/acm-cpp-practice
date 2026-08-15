#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    
    ll ans = 0; 
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ll group = i / 2;
         
        if (group % 2 == 0) 
        {
            ans += x;
        }
        else 
        {
            ans -= x;
        }
    }
    
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    moink();
    return 0;
}
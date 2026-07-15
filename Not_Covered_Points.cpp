#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<ll> pos(n + 1);
    for (int i = 0; i < n; i++) 
    {
        ll x, y;
        cin >> x >> y;
        pos[x] = y; 
    }

    
    ll min_val = n + 1; 
    ll ans = 0;

    for (int i = 1; i <= n; i++) 
    {
        if (pos[i] < min_val) 
        { 
            ans++;              
            min_val = pos[i];   
        }
    }
    cout << ans << endl;
    return 0;
}
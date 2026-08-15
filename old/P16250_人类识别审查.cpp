#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
    
int main()
{
    int n;
    cin >> n;
    vector<ll> diff(n + 2, 0);

    for (int i = 0; i < n;i++)
    {
        ll a, b;
        cin >> a >> b;
        diff[a] += 1;
        diff[b + 1] -= 1;
    }

    ll ans = -1;
    ll cur = 0;
    for (int k = 0; k <= n; k++) 
    {
        cur += diff[k];
        if (cur == k) 
        {
            ans = k; 
        }
    }
    cout << ans << endl;
    return 0;
}                                                                                         
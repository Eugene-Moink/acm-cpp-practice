#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll getMaxPrimeFactor(ll x) 
{
    ll max_factor = 1;
    for (int i = 2; i * i <= x; i++) 
    {
        while (x % i == 0) {
            max_factor = i;
            x /= i;
        }
    }
    if (x > 1) max_factor = x;
    return max_factor;
}

int main()
{
    ll m, n;
    cin >> m >> n;
    for (int i = m; i <= n;i++)
    {
        ll temp = i;
        ll ans = getMaxPrimeFactor(temp);
        cout << ans;
        if(i<n)
        {
            cout << ",";
        }
    }

    return 0;
}
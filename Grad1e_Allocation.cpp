#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll sum=0;
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        sum += temp;
    }
    ll ans = min(sum, m);
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
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
const ll mod = 100;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    vector<ll> cnts(101, 0);
    ll ans = 0;
    for (ll i = 0; i < n;i++)
    {
        ll x = arr[i];
        for (ll j = x + 1; j <= 100;j++)
        {
            ans = (ans + cnts[j]) % mod;
        }
        cnts[x]++;
    }

    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
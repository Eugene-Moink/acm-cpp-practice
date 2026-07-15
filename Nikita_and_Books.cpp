#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll sum = 0;
    bool ok = 1;

    for (ll i = 1; i <= n;i++)
    {
        ll x;
        cin >> x;
        sum += x;

        if(ok)
        {
            ll need = i * (i + 1) / 2;
            if(sum<need)
            {
                ok = 0;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
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
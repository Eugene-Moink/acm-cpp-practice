#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> num(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> num[i];
    }

    ll g = __gcd(x, y);

    if (g == 1)
    {
        cout << "YES" << endl;
        return;
    }

    for (ll i = 0; i < n; i++)
    {
        if (i % g != (num[i] - 1) % g)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
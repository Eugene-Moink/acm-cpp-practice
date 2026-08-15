#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> a[i];
    }

    while(m--)
    {
        ll l, r;
        cin >> l >> r;
        reverse(a.begin() + l - 1, a.begin() + r);
    }

    for(ll i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    moink();
    return 0;
}
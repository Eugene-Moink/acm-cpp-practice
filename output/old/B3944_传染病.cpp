#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll mod = 722733748;
    ll k, a, q;
    cin >> k >> a >> q;
    ll total = 1;
    ll current = a;

    for (ll i = 1; i <= k;i++)
    {
        total = (total * current) % mod;
        current = (current * q) % mod;
    }
    cout << total << endl;
    return 0;
}
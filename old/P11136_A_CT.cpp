#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
#define mod 988444333

int main()
{
    ll a, b, h, k;
    cin >> a >> b >> h >> k;

    ll ans = ((a + k) % mod * (b + k) % mod * (h + k) % mod) % mod;
    cout << ans << endl;
    return 0;
}
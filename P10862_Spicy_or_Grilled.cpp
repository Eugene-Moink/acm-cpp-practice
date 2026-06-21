#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, x, a, b;
        cin >> n >> x >> a >> b;
        ll ans = x * b + (n - x) * a;
        cout << ans << endl;
    }
    return 0;
}
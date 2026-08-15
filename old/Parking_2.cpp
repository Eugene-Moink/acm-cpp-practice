#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;
    ll start = max(a, l);
    ll end = min(b, r);
    ll sp_time = 0;
    if(start<end)
    {
        sp_time = end - start;
        ll nor_time = b - a - sp_time;
        ll ans = sp_time * x + nor_time * y;
        cout << ans << endl;
    }
    else
    {
        ll ans = (b - a) * y;
        cout << ans << endl;
    }
    return 0;
}
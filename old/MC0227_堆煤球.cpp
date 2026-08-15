#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for (ll i = l; i <= r;i++)
    {
        if(i%8==0)
        {
            continue;
        }
        ans += i * (i + 1) / 2;
    }
    cout << ans << endl;
}

#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    if (2 * a <= b)
    {
        ans = n * a;
    }

    else
    {
        ans = (n / 2) * b + (n % 2) * a;
    }
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
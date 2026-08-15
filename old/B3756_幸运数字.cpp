#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool cheak(ll x, ll base)
{
    while (x > 0)
    {
        ll dight = x % base;
        if (dight == 0)
        {
            return 0;
        }
        x /= base;
    }
    return 1;
}

void moink()
{
    ll a, b;
    ll ans = 0;
    cin >> a >> b;
    for (ll i = a; i <= b;i++)
    {
        if (cheak(i, 5) && cheak(i, 7) && cheak(i, 9))
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
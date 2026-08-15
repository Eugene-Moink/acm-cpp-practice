#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
const ll mod = 1000000007;

void moink()
{
    string s;
    cin >> s;
    ll cnt = 0;
    ll ans = 0;
    for (char c : s)
    {
        if(c=='1')
        {
            cnt++;
        }
        else
        {
            ll len = cnt;
            ll add = (len * (len + 1) / 2) % mod;
            ans = (ans + add) % mod;
            cnt = 0;
        }
    }
    if (cnt > 0)
    {
        ll len = cnt;
        ll add = (len * (len + 1) / 2) % mod;
        ans = (ans + add) % mod;
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
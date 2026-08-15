#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool check(ll x)
{
    if (x % 7 == 0)
    {
        return 1;
    }

    string s = to_string(x);
    for (ll i = 0; i < s.size();i++)
    {
        if(s[i]=='7')
        {
            return 1;
        }
    }

    return 0;
}

void moink()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n;i++)
    {
        if(!check(i))
        {
            ans += i;
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
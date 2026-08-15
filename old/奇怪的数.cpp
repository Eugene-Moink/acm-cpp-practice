#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool check(ll x)
{
    string s = to_string(x);
    ll ans = 0;
    for (ll i = 0; i < s.size();i++)
    {
        ans += s[i] - '0';
    }
    if(ans==10)
    {
        return 1;
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
        if(check(i))
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
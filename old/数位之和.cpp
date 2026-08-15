#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 0; i < n;i++)
    {
        ll x;
        cin >> x;
        string s = to_string(x);
        for(char c : s)
        {
            ans += (c - '0');
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = n;

    for (ll i = 0; i < n - 1;i++)
    {
        if(s[i]!=s[i+1])
        {
            ans += (i + 1);
        }
    }
    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
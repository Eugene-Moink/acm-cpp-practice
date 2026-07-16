#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (2 *k > n)
    {
        cout << "-1" << endl;
        return;
    }

    ll r_need = 0;
    ll l_need = 0;
    for (ll i = 0; i < k;i++)
    {
        if(s[i]!='R')
            r_need++;
    }
    for (ll i = n-1; i >= n - k;i--)
    {
        if(s[i]!='L')
        {
            l_need++;
        }
    }
    ll ans = r_need + l_need;
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
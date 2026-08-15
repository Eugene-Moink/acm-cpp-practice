#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> num(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> num[i];
    }

    for (ll i = 0; i < n;i++)
    {
        ll x;
        string s;
        cin >> x >> s;
        for (ll j = 0; j < x;j++)
        {
            if (s[j] == 'D')
            {
                num[i] = (num[i] + 1) % 10;
            }
            else
            {
                num[i] = (num[i] - 1 + 10) % 10;
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        cout << num[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
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
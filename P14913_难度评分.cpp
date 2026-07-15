#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> num;
    for (ll i = 0; i < n;i++)
    {
        ll val;
        cin >> val;
        num.push_back(val);
    }

    for (ll i = 0; i < m;i++)
    {
        ll order, diff;
        cin >> order >> diff;
        string s;
        cin >> s;

        if(s=="Completed")
        {
            num[order - 1] = diff;
        }
    }

    for (ll i = 0; i < n;i++)
    {
        cout<<num[i];
        if(i<n-1)
        {
            cout << " ";
        }
    }
    return 0;
}
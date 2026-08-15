#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> re(n + 1);
    for (ll i = 1; i <= n;i++)
    {
        ll k;
        cin >> k;
        for (ll j = 0; j < k;j++)
        {
            ll to;
            cin >> to;
            re[to].push_back(i);
        }
    }

    for (ll i = 1; i <= n;i++)
    {
        cout << re[i].size();
        if(re[i].size()==0)
        {
            cout << endl;
            continue;
        }

        for (ll j = 0; j < re[i].size(); j++) 
        {
            cout << " " << re[i][j];
        }
        cout << endl;
    }
    return 0;
}
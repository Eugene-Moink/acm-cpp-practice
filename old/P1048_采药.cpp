#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll t, m;
    cin >> t >> m;
    vector<ll> dp(t + 1, 0);
    for (ll i = 0; i < m;i++)
    {
        ll time, val;
        cin >> time >> val;
        for (ll j = t; j >= time;j--)
        {
            dp[j] = max(dp[j], dp[j - time] + val);
        }
    }
    cout << dp[t] << endl;
}

int main()
{
    moink();
    return 0;
}
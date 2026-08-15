#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>> player(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> player[i].first;
        player[i].second = i + 1;
    }

    sort(player.begin(), player.end());
    cout << player[n - 2].second << endl; 
}

int main()
{
    solve();
    return 0;
}

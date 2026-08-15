#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<bool> isolated(m + 1, 0);

    vector<ll> room(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> room[i];
    }

    ll v;
    cin >> v;

    for (ll i = 0; i < k;i++)
    {
        ll u;
        cin >> u;
        isolated[u] = 1;
    }

    ll ans = 0;
    for (ll i = 0; i < n;i++)
    {
        ll group = room[i];
        if(!isolated[group])
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
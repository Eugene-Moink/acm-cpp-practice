#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, k, m;
    cin >> n >> k >> m;

    unordered_map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++)
    {
        ll c, v;
        cin >> c >> v;
        mp[c].push_back(v);
    }

    for (auto &p : mp)
    {
        sort(p.second.begin(), p.second.end(), greater<ll>());
    }

    vector<ll> must_pick, free_pick;
    for (auto &p : mp)
    {
        auto &vec = p.second;
        must_pick.push_back(vec[0]);
        for (int i = 1; i < vec.size(); i++)
            free_pick.push_back(vec[i]);
    }

    sort(must_pick.begin(), must_pick.end(), greater<ll>());
    sort(free_pick.begin(), free_pick.end(), greater<ll>());

    ll ans = 0;

    for (int i = 0; i < m && i < must_pick.size(); i++)
        ans += must_pick[i];

    vector<ll> rest;
    for (int i = m; i < must_pick.size(); i++)
        rest.push_back(must_pick[i]);
    for (auto x : free_pick)
        rest.push_back(x);

    sort(rest.begin(), rest.end(), greater<ll>());

    int need = k - m;
    for (int i = 0; i < need && i < rest.size(); i++)
        ans += rest[i];

    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m;i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<ll> dist(n + 1, 1e18);
    dist[s] = 0;

    priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        ll u = top.second;
        ll d = top.first;
        if (d != dist[u])
        {
            continue;
        }

        for (auto &edge : adj[u])
        {
            ll v = edge.first;
            ll w = edge.second;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (ll i = 1; i <= n;i++)
    {
        cout << dist[i];
        if (i < n)
        {
            cout << " ";
        }
    }
}
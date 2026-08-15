#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i <= n;i++)
    {
        ll u, k;
        cin >> u >> k;
        adj[u].resize(k);
        for (ll j = 0; j < k;j++)
        {
            cin >> adj[u][j];
        }
    }

    vector<ll> dist(n + 1, -1);
    queue<ll> q;
    dist[1] = 0;
    q.push(1);

    while(!q.empty())
    {
        ll u = q.front();
        q.pop();

        for(ll v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (ll i = 1; i <= n;i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

int main()
{
    moink();
    return 0;
}
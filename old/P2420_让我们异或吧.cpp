#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge
{
    int to;
    int weight;
};

void moink()
{
    int n;
    cin >> n;
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> xr(n + 1, 0);
    function<void(int, int)> dfs = 
    [&](int u, int parent) 
    {
        for (auto &e : adj[u]) 
        {
            int v = e.to;
            int w = e.weight;
            if (v == parent) continue;
            xr[v] = xr[u] ^ w;
            dfs(v, u);
        }
    };
    dfs(1, 0);
    int m;
    cin >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        cout << (xr[u] ^ xr[v]) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
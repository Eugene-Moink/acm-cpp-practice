#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const int LOG = 21;

vector<int> adj[MAXN];
int dep[MAXN];
int up[MAXN][LOG];

void dfs(int u, int p)
{
    dep[u] = dep[p] + 1;
    up[u][0] = p;

    for (int j = 1; j < LOG; j++)
    {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);

    int diff = dep[u] - dep[v];
    for (int j = 0; j < LOG; j++)
    {
        if ((diff >> j) & 1)
        {
            u = up[u][j];
        }
    }

    if (u == v)
        return u;

    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dep[0] = 0;
    dfs(1, 0);

    long long ans = dep[n] - 1;

    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;

        int l = lca(v, n);

        if (l != 1)
        {
            long long new_dist = 1LL + dep[v] + dep[n] - 2LL * dep[l];
            if (new_dist > ans)
            {
                ans = new_dist;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
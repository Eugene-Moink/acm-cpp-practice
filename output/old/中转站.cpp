#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const int maxn = 505;
vector<int> adj[maxn];
bool vis[maxn];

void dfs(int u)
{
    vis[u] = 1;
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

void moink()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) 
    {
        adj[i].clear();
        vis[i] = false;
    }

    for (int i = 0; i < m;i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    dfs(1);

    if(vis[n])
        cout << "Yes" << endl;

    else
        cout << "No" << endl;
}

int main()
{
    moink();
    return 0;
}
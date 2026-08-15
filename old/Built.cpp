#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

struct DSU
{
    vector<ll> parent, size;
    DSU(ll n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (ll i = 0; i <= n;i++)
        {
            parent[i] = i;
        }
    }

    ll find(ll x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(ll x,ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return 0;
        }

        if(size[x]<size[y])
        {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        return 1;
    }
};

struct town 
{
    ll x, y;
};

struct edge 
{ 
    ll u, v, cost;
};

void moink()
{
    ll n;
    cin >> n;
    vector<town>towns(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> towns[i].x >> towns[i].y;
    }

    vector<ll> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](ll a, ll b)
         { return towns[a].x < towns[b].x; });

    DSU dsu(n);
    vector<edge> edges;

    sort(order.begin(), order.end(), [&](ll a, ll b)
         { return towns[a].x < towns[b].x; });
    for (ll i = 0; i < n - 1;i++)
    {
        ll u = order[i];
        ll v = order[i + 1];
        ll cost = towns[v].x - towns[u].x;
        edges.push_back({u, v, cost});
    }

    sort(order.begin(), order.end(), [&](ll a, ll b)
         { return towns[a].y < towns[b].y; });
    for (ll i = 0; i < n - 1;i++)
    {
        ll u = order[i];
        ll v = order[i + 1];
        ll cost = towns[v].y - towns[u].y;
        edges.push_back({u, v, cost});
    }

    sort(edges.begin(), edges.end(), [&](const edge &a, const edge &b)
         { return a.cost < b.cost; });

    ll ans = 0;
    ll cnt = 0;
    for (ll i = 0; i < (ll)edges.size();i++)
    {
        ll u = edges[i].u;
        ll v = edges[i].v;
        ll cost = edges[i].cost;

        if (dsu.unite(u, v)) 
        {
            ans += cost;
            cnt++;

            if (cnt == n - 1)
            {
                break;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
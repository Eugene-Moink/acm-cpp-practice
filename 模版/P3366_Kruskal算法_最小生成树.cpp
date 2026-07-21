#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

struct Edge
{
    ll u, v, w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

const ll MAXN = 200005;
ll fa[MAXN];

void init(ll n)
{
    for (ll i = 1; i <= n;i++)
    {
        fa[i] = i;
    }
}

ll find(ll x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void merge(ll x,ll y)
{
    ll fx = find(x);
    ll fy = find(y);
    if (fx != fy)
    {
        fa[fx] = fy;
    }
}

void moink()
{
    ll n, m;
    cin >> n >> m;
    init(n);

    vector<Edge> edges(m);
    for (ll i = 0; i < m;i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());

    ll ans = 0, cnt = 0;
    for (auto &e : edges)
    {
        if (find(e.u) != find(e.v))
        {
            merge(e.u, e.v);
            ans += e.w;
            cnt++;
        }
    }

    if (cnt == n - 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "orz" << endl;
    }
}

int main()
{
    moink();
    return 0;
}
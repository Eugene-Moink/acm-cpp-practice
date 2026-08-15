#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const ll MAXN = 10005;
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
    if(x==fa[x])
    {
        return x;
    }
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
    ll n, m, p;
    cin >> n >> m >> p;
    init(n);
    for (ll i = 1; i <= m;i++)
    {
        ll a, b;
        cin >> a >> b;
        merge(a, b);
    }
    for (ll i = 1; i <= p;i++)
    {
        ll c, d;
        cin >> c >> d;
        if (find(c) == find(d))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

int main()
{
    moink();
    return 0;
}
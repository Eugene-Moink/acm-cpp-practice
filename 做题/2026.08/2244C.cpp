#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;
int fa[MAXN];
void init(ll n)
{
    for (ll i = 0; i <= n; i++)
    {
        fa[i] = i;
    }
}

ll find(ll x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = find(fa[x]);
}

void merge(ll x, ll y)
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }

    init(n);

    for (int i = 1; i <= n; i++)
    {
        if (i + x <= n)
            merge(i, i + x);
        if (i + y <= n)
            merge(i, i + y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (find(i) != find(p[i]))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
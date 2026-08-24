#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const ll MAXN = 200005;
ll fa[MAXN];

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
    ll n, m;
    cin >> n >> m;

    init(n);
    while (m--)
    {
        char op;
        ll x, y;
        cin >> op >> x >> y;

        if (op == '1')
        {
            merge(x, y);
        }

        else if (op == '2')
        {
            if (find(x) == find(y))
            {
                cout << "Y" << endl;
            }

            else
            {
                cout << "N" << endl;
            }
        }
    }
}

int main()
{
    moink();
    return 0;
}
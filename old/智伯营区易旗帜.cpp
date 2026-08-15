#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for (ll i = 1; i <= n;i++)
    {
        cin >> a[i];
    }

    struct query
    {
        ll l, r, v;
    };

    vector<query> ops(q);
    for (ll i = 0; i < q;i++)
    {
        cin >> ops[i].l >> ops[i].r >> ops[i].v;
    }

    vector<ll> ans(n + 1, 0);
    vector<ll> next(n + 2);
    for (ll i = 1; i <= n + 1;i++)
    {
        next[i] = i;
    }

    function<ll(ll)> find = [&](ll x)
    {
        if (next[x] == x)
        {
            return x;
        }
        return next[x] = find(next[x]);
    };

    for (ll i = q - 1; i >= 0;i--)
    {
        ll l = ops[i].l;
        ll r = ops[i].r;
        ll v = ops[i].v;

        ll pos = find(l);

        while (pos <= r)
        {
            ans[pos] = v;
            next[pos] = find(pos + 1);
            pos = find(pos);
        }
    }

    for (ll i = 1; i <= n;i++)
    {
        if(ans[i]==0)
        {
            cout << a[i] << " ";
        }
        else
        {
            cout << ans[i] << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}
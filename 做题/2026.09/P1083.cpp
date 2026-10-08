#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1000005;
int n, m;
ll r[MAXN];
ll diff[MAXN];

struct Order
{
    ll d;
    int s, t;
} orders[MAXN];

bool check(int k)
{
    for (int i = 1; i <= k; i++)
    {
        diff[orders[i].s] += orders[i].d;
        diff[orders[i].t + 1] -= orders[i].d;
    }

    ll cur = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        cur += diff[i];
        if (cur > r[i])
        {
            ok = false;
            break;
        }
    }

    for (int i = 1; i <= k; i++)
    {
        diff[orders[i].s] -= orders[i].d;
        diff[orders[i].t + 1] += orders[i].d;
    }

    return ok;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> orders[i].d >> orders[i].s >> orders[i].t;
    }

    if (check(m))
    {
        cout << 0 << '\n';
        return;
    }

    int lo = 1, hi = m;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
            lo = mid + 1;
        else
            hi = mid;
    }

    cout << -1 << '\n'
         << lo << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
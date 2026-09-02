#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20005;
int fa[MAXN];
bitset<MAXN> dp;

void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    while (fa[x] != x)
    {
        fa[x] = fa[fa[x]];
        x = fa[x];
    }
    return x;
}

int merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        fa[fx] = fy;
    return 0;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    init(n);
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }

    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cnt[find(i)]++;

    vector<int> blocks;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] != 0)
            blocks.push_back(cnt[i]);
    }

    dp.reset();
    dp[0] = 1;
    for (int x : blocks)
    {
        dp |= (dp << x);
    }

    int low = -1, high = -1;
    for (int i = m; i >= 0; i--)
        if (dp[i])
        {
            low = i;
            break;
        }
    for (int i = m; i <= n; i++)
        if (dp[i])
        {
            high = i;
            break;
        }

    if (low == -1)
        cout << high << '\n';
    else if (high == -1)
        cout << low << '\n';
    else
    {
        if (abs(m - low) <= abs(high - m))
            cout << low << '\n';
        else
            cout << high << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
    vector<int> fa;

    DSU(int n = 0) { init(n); }

    void init(int n)
    {
        fa.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
    }

    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
            fa[fx] = fy;
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }
};

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        struct Query
        {
            int i, j, e;
        };
        vector<Query> qs;
        vector<int> alls;

        for (int k = 0; k < n; k++)
        {
            int i, j, e;
            cin >> i >> j >> e;
            qs.push_back({i, j, e});
            alls.push_back(i);
            alls.push_back(j);
        }

        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());

        auto get_id = [&](int x)
        {
            return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
        };

        DSU dsu(alls.size());

        for (auto &q : qs)
        {
            if (q.e == 1)
                dsu.merge(get_id(q.i), get_id(q.j));
        }

        bool ok = true;
        for (auto &q : qs)
        {
            if (q.e == 0)
            {
                if (dsu.isSame(get_id(q.i), get_id(q.j)))
                {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
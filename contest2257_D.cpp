#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<vector<int>> children(n + 1);
    vector<int> parent(n + 1, 0);
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        parent[i] = p;
        children[p].push_back(i);
    }

    int m;
    cin >> m;
    vector<int> is_target(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a;
        cin >> a;
        is_target[a] = 1;
    }

    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        if (is_target[i])
            cnt[i] = 1;

    for (int i = n; i >= 2; --i)
        cnt[parent[i]] += cnt[i];

    vector<int> ans;
    for (int v = 1; v <= n; ++v)
    {
        int child_targets = 0;
        for (int u : children[v])
            if (cnt[u] > 0)
                child_targets++;

        int branches = child_targets + (is_target[v] ? 1 : 0);

        if (branches < 2)
            continue;

        if (is_target[v])
        {
            for (int u : children[v])
                if (cnt[u] > 0)
                    ans.push_back(u);
        }
        else
        {
            bool first = true;
            for (int u : children[v])
                if (cnt[u] > 0)
                {
                    if (first)
                    {
                        first = false;
                        continue;
                    }
                    ans.push_back(u);
                }
        }
    }

    cout << ans.size();
    for (int u : ans)
        cout << ' ' << u;
    cout << '\n';
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    map<int, int> cnt;
    for (int i = 1; i <= n;i++)
    {
        cnt[deg[i]]++;
    }

    int y = 0;
    int x = 0;
    bool found = false;
    for (auto &p : cnt)
    {
        if(p.second==1)
        {
            x = p.first;
            found = 1;
            break;
        }
    }
    if(found)
    {
        y = cnt[1] / x;
    }
    else
    {
        int d = -1;
        for (auto &p : cnt) 
        {
            if (p.first != 1) 
            {   
                d = p.first;
                break;
            }
        }
        x = cnt[d] - 1;
        y = cnt[1] / x;
    }
    cout << x << " " << y << '\n';
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
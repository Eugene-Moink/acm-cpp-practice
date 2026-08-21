#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    cin >> n >> m;
    bool vis[n] = {false};

    while (m--)
    {
        int x;
        cin >> x;
        vis[x] = 1;
    }

    vector<int> pos;
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            pos.push_back(i);
            ok = 0;
        }
    }

    if (ok)
    {
        cout << n << '\n';
        return;
    }
    else
    {
        for (int x : pos)
        {
            cout << x << ' ';
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
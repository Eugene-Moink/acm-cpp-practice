#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 20005;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> dist(MAX, -1);
    queue<int> q;

    dist[n] = 0;
    q.push(n);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == m)
        {
            cout << dist[u] << '\n';
            return;
        }

        int v1 = u - 1;
        if (v1 >= 1 && dist[v1] == -1)
        {
            dist[v1] = dist[u] + 1;
            q.push(v1);
        }

        int v2 = u * 2;
        if (v2 < MAX && dist[v2] == -1)
        {
            dist[v2] = dist[u] + 1;
            q.push(v2);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
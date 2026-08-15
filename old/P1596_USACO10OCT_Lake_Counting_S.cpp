#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int n, m;
vector<string> grid;

ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(ll x,ll y)
{
    grid[x][y] = '.';

    for (ll i = 0; i < 8;i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;

        if(grid[nx][ny]=='W')
        {
            dfs(nx,ny);
        }
    }
}

void solve()
{
    cin >> n >> m;

    grid.resize(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> grid[i];
    }

    ll ans = 0;
    for (ll i = 0; i < n;i++)
    {
        for (ll j = 0; j < m;j++)
        {
            if(grid[i][j]=='W')
            {
                ans++;
                dfs(i,j);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
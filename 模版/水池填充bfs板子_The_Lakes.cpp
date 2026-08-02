#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin >> grid[i][j];
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    ll ans = 0;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if (grid[i][j] != 0)
            {
                ll sum = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                sum += grid[i][j];
                grid[i][j] = 0;

                while(!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    int x = cur.first;
                    int y = cur.second;

                    for (int d = 0; d < 4;d++)
                    {
                        int n_x = x + dx[d];
                        int n_y = y + dy[d];

                        if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= m)
                        {
                            continue;
                        }
                        if(grid[n_x][n_y] == 0)
                        {
                            continue;
                        }

                        sum += grid[n_x][n_y];
                        grid[n_x][n_y] = 0;
                        q.push({n_x,n_y});
                    }
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}               
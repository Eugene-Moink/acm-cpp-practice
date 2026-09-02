#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; ++i)
        cin >> a[i];

    vector<string> b(H, string(W, '.'));
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (a[i][j] == '#')
            {
                for (int k = 0; k < 8; ++k)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && a[nx][ny] == '.')
                    {
                        b[nx][ny] = '#';
                    }
                }
            }
        }
    }

    const int inf = 1000000010;
    vector<vector<int>> D(H, vector<int>(W, inf));
    queue<pair<int, int>> q;

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (b[i][j] == '#')
            {
                D[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        for (int k = 0; k < 8; ++k)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && D[nx][ny] == inf)
            {
                D[nx][ny] = D[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (D[i][j] % 2 == 0)
                cout << '.';
            else
                cout << '#';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;

void moink()
{
    int h, w;
    cin >> h >> w;
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;

    ch--, cw--, dh--, dw--;
    vector<string> s(h);
    for (auto &str : s)
    {
        cin >> str;
    }

    vector<vector<int>> dist(h, vector<int>(w, inf));
    dist[ch][cw] = 0;

    deque<pair<int, int>> dq;
    dq.push_front({ch, cw});

    while (!dq.empty())
    {
        int r = dq.front().first;
        int c = dq.front().second;
        dq.pop_front();

        if (r == dh && c == dw)
            break;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                continue;
            if (s[nr][nc] == '#')
                continue;
            if (dist[nr][nc] <= dist[r][c])
                continue;

            dist[nr][nc] = dist[r][c];
            dq.push_front({nr, nc});
        }

        for (int dr = -2; dr <= 2; dr++)
        {
            for (int dc = -2; dc <= 2; dc++)
            {
                if (dr == 0 && dc == 0)
                    continue;

                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                    continue;
                if (s[nr][nc] == '#')
                    continue;
                if (dist[nr][nc] <= dist[r][c] + 1)
                    continue;

                dist[nr][nc] = dist[r][c] + 1;
                dq.push_back({nr, nc});
            }
        }
    }

    if (dist[dh][dw] == inf)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << dist[dh][dw] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
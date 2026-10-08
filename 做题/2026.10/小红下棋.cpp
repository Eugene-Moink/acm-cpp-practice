#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string g[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> g[i];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (g[i][j] == '*')
            {
                g[i][j] = '1';

                bool win = false;
                for (int r = 0; r < 3; r++)
                    if (g[r][0] == '1' && g[r][1] == '1' && g[r][2] == '1')
                        win = true;
                for (int c = 0; c < 3; c++)
                    if (g[0][c] == '1' && g[1][c] == '1' && g[2][c] == '1')
                        win = true;
                if (g[0][0] == '1' && g[1][1] == '1' && g[2][2] == '1')
                    win = true;
                if (g[0][2] == '1' && g[1][1] == '1' && g[2][0] == '1')
                    win = true;

                if (win)
                {
                    cout << "Yes\n"
                         << i + 1 << ' ' << j + 1 << '\n';
                    return;
                }

                g[i][j] = '*';
            }
        }
    }
    cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, K;
    cin >> R >> C >> K;
    vector<string> grid(R);
    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
    }

    int ans = 0;

    if (K == 1)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (grid[i][j] == '.')
                    ans++;
            }
        }
    }
    else
    {
        for (int i = 0; i < R; i++)
        {
            int cnt = 0;
            for (int j = 0; j < C; j++)
            {
                if (grid[i][j] == '.')
                {
                    cnt++;
                    if (cnt >= K)
                        ans++;
                }
                else
                {
                    cnt = 0;
                }
            }
        }

        for (int j = 0; j < C; j++)
        {
            int cnt = 0;
            for (int i = 0; i < R; i++)
            {
                if (grid[i][j] == '.')
                {
                    cnt++;
                    if (cnt >= K)
                        ans++;
                }
                else
                {
                    cnt = 0;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
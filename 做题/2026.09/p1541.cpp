#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[45][45][45][45];

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> score(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> score[i];
    }

    int cnt[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    dp[0][0][0][0] = score[1];
    for (int a = 0; a <= cnt[1]; ++a)
    {
        for (int b = 0; b <= cnt[2]; ++b)
        {
            for (int c = 0; c <= cnt[3]; ++c)
            {
                for (int d = 0; d <= cnt[4]; ++d)
                {
                    int pos = 1 + a + b * 2 + c * 3 + d * 4;
                    if (a > 0)
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + score[pos]);
                    if (b > 0)
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + score[pos]);
                    if (c > 0)
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + score[pos]);
                    if (d > 0)
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + score[pos]);
                }
            }
        }
    }

    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
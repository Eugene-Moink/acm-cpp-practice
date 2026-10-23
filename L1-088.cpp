#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, S;
    cin >> N >> K >> S;

    vector<int> total_cnt(300, 0);
    vector<int> vip_cnt(300, 0);

    for (int i = 0; i < N; i++)
    {
        int score, pat;
        cin >> score >> pat;
        if (score >= 175)
        {
            total_cnt[score]++;
            if (pat >= S)
            {
                vip_cnt[score]++;
            }
        }
    }

    int ans = 0;
    for (int score = 175; score <= 290; score++)
    {
        if (total_cnt[score] == 0)
            continue;

        if (vip_cnt[score] > 0)
        {

            ans += total_cnt[score];
        }
        else
        {
            ans += min(K, total_cnt[score]);
        }
    }

    cout << ans << '\n';
    return 0;
}
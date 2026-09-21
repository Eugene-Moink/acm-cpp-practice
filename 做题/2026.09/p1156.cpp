#include <bits/stdc++.h>
using namespace std;

struct Trash
{
    int t, f, h;
};

void solve()
{
    int D, G;
    cin >> D >> G;
    vector<Trash> trash(G);
    for (int i = 0; i < G; i++)
    {
        cin >> trash[i].t >> trash[i].f >> trash[i].h;
    }

    sort(trash.begin(), trash.end(), [](Trash a, Trash b)
         { return a.t < b.t; });

    vector<int> dp(D + 1, -1);
    dp[0] = 10;

    for (int i = 0; i < G; i++)
    {
        int t = trash[i].t, f = trash[i].f, h = trash[i].h;
        for (int j = D; j >= 0; j--)
        {
            if (dp[j] >= t)
            {
                if (j + h >= D)
                {
                    cout << t << endl;
                    return;
                }

                int life = dp[j];

                dp[j + h] = max(dp[j + h], life);

                dp[j] = life + f;
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
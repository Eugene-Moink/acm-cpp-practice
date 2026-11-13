#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    bool is_win[35] = {false};
    for (int i = 0; i < 7; i++)
    {
        int num;
        cin >> num;
        is_win[num] = true;
    }

    vector<int> ans(7, 0);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 7; j++)
        {
            int num;
            cin >> num;
            if (is_win[num])
            {
                cnt++;
            }
        }

        if (cnt > 0)
        {
            ans[7 - cnt]++;
        }
    }

    for (int i = 0; i < 7; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
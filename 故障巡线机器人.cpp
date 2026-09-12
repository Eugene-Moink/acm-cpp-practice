#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    vector<int> pos(n + 1, 0);
    vector<int> pre_min(n + 1), pre_max(n + 1);
    pre_min[0] = pre_max[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pos[i] = pos[i - 1];
        if (s[i - 1] == 'L')
            pos[i]--;
        else if (s[i - 1] == 'R')
            pos[i]++;

        pre_min[i] = min(pre_min[i - 1], pos[i]);
        pre_max[i] = max(pre_max[i - 1], pos[i]);
    }

    vector<int> q_pos;
    for (int i = o; i < n; i++)
    {
        if (s[i] == '?')
            q_pos.push_back(i);
    }
    int cur = q_pos.size();

    vector<int> suf_min(n + 1), suf_max(n + 1);
    suf_min[n] = suf_max[n] = pos[n];
    for (int i = n - 1; i >= 0; i--)
    {
        suf_min[i] = min(suf_min[i + 1], pos[i]);
        suf_max[i] = max(suf_max[i + 1], pos[i]);
    }

    int ans = INT_MAX;
    int cnt = q_pos.size();

    for (int k = 0; k <= cnt; k++)
    {
        int cur_min, cur_max;

        if (k == 0)
        {

            int delta = cnt;
            cur_min = min(0, suf_min[0] + delta);
            cur_max = max(0, suf_max[0] + delta);
        }

        else if (k == cnt)
        {

            int p = q_pos[cnt - 1];
            cur_min = pre_min[p + 1];
            cur_max = pre_max[p + 1];
        }
        else
        {

            int p = q_pos[k - 1];
            int delta = cnt - 2 * k;

            int left_min = pre_min[p + 1];
            int left_max = pre_max[p + 1];
            int right_min = suf_min[p + 1] + delta;
            int right_max = suf_max[p + 1] + delta;

            cur_min = min(left_min, right_min);
            cur_max = max(left_max, right_max);
        }

        ans = min(ans, cur_max - cur_min + 1);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
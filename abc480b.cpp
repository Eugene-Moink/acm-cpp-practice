#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> cnt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cnt[i].first;
    }

    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;

        int exact_idx = -1;
        int match_count = 0;
        int match_idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (cnt[j].first.size() == t.size())
            {
                int diff = 0;
                for (int k = 0; k < (int)t.size(); k++)
                {
                    if (t[k] != cnt[j].first[k])
                        diff++;
                    if (diff > 1)
                        break;
                }

                if (diff == 0)
                {
                    exact_idx = j;
                    break;
                }

                if (diff == 1)
                {
                    match_count++;
                    match_idx = j;
                }
            }
        }

        if (exact_idx != -1)
        {
            cnt[exact_idx].second++;
        }
        else if (match_count == 1)
        {
            cnt[match_idx].second++;
        }
    }

    for (auto p : cnt)
    {
        cout << p.second << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
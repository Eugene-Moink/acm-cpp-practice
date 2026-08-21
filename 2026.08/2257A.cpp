#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    cin >> n >> m;
    vector<string> words(n);
    for (auto &s : words)
        cin >> s;

    vector<string> abbrs(m);
    for (auto &s : abbrs)
        cin >> s;

    int cnt[26] = {0};
    for (auto &s : words)
    {
        cnt[s[0] - 'a']++;
    }

    vector<bool> used(m, false);

    while (1)
    {
        bool prog = 0;
        for (int j = 0; j < m; j++)
        {
            if (used[j])
                continue;

            bool ok = 1;
            for (char c : abbrs[j])
            {
                if (cnt[c - 'A'] == 0)
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                used[j] = 1;
                cnt[abbrs[j][0] - 'A']++;
                prog = 1;
            }
        }
        if (!prog)
            break;
    }

    bool all = true;
    for (int i = 0; i < m; i++)
    {
        if (!used[i])
        {
            all = false;
            break;
        }
    }
    cout << (all ? "YES" : "NO") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
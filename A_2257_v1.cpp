#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    cin >> n >> m;
    bool find[26] = {0};
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        find[s[0] - 'a'] = 1;
    }

    bool all_ok = true;
    for (int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        bool ok = 1;
        for (char c : s)
        {
            if (!find[c - 'A'])
            {
                ok = 0;
                break;
            }
        }
        if (!ok)
            all_ok = false;
    }
    cout << (all_ok ? "YES" : "NO") << '\n';
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
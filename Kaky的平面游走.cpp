#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> a;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    int cur_x = 0, cur_y = 0, cnt_n = 0;
    for (int i = 0; i <= n; i++)
    {
        for (auto &p : a)
        {
            if (abs(cur_x - p.first) + abs(cur_y - p.second) <= cnt_n)
            {
                cout << "Yes" << '\n';
                return;
            }
        }
        if (i == n)
            break;
        if (s[i] == 'U')
            cur_x--;
        else if (s[i] == 'D')
            cur_x++;
        else if (s[i] == 'L')
            cur_y--;
        else if (s[i] == 'R')
            cur_y++;
        else if (s[i] == 'N')
            cnt_n++;
    }
    cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
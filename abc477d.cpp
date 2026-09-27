#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> has_tile(n, 0);
    vector<char> locked_color(n, 'a');
    char cur_color = 'a';

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos;
            cin >> pos;
            pos--;
            if (!has_tile[pos])
            {
                has_tile[pos] = 1;
                locked_color[pos] = cur_color;
            }
            else
            {
                has_tile[pos] = 0;
            }
        }
        else
        {
            char s;
            cin >> s;
            cur_color = s;
        }
    }

    string ans(n, ' ');
    for (int i = 0; i < n; i++)
    {
        ans[i] = has_tile[i] ? locked_color[i] : cur_color;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
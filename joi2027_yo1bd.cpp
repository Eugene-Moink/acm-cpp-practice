#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int r, c;
    cin >> r >> c;
    vector<string> str(r);
    for (string &s : str)
        cin >> s;

    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((j + 1 < c) && (str[i][j] == 'R') && (str[i][j + 1] == 'L'))
                ans++;
            if ((i + 1 < r) && (str[i][j] == 'D') && (str[i + 1][j] == 'U'))
                ans++;
        }
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
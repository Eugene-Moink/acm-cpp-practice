#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    char color = 'R';
    for (char c : s)
    {
        if (color != c)
        {
            ans++;
            color = c;
        }

        if (color == 'R')
        {
            color = 'B';
        }
        else
        {
            color = 'R';
        }
    }
    cout << ans << "\n";
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
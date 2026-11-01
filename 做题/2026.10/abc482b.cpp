#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    vector<string> s(5);
    for (string &str : s)
        cin >> str;

    int ans = 10;
    for (int i = 0; i < 3; i++)
    {
        int dot = 0;
        for (int j = 0; j < 5; j++)
        {
            if (s[i][j] == '.')
                dot++;
        }
        ans = min(ans, dot);
    }

    for (int j = 0; j < 5; j++)
    {
        int dot = 0;
        for (int i = 0; i < 5; i++)
        {
            if (s[i][j] == '.')
                dot++;
        }
        ans = min(ans, dot);
    }

    int tmp1 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (s[i][i] == '.')
            tmp1++;
    }
    ans = min(ans, tmp1);

    int tmp2 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (s[i][4 - i] == '.')
            tmp2++;
    }
    ans = min(ans, tmp2);

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
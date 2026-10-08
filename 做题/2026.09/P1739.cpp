#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s)
    {
        if (cnt < 0)
        {
            cout << "NO\n";
            return;
        }

        if (c == '(')
            cnt++;

        if (c == ')')
            cnt--;

        if (c == '@')
            break;
    }

    if (cnt == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
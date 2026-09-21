#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    for (int i = 0; i < n; i++)
    {
        if (t[i] == '*')
            continue;
        if (s[i] != t[i])
        {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
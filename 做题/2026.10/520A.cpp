#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> seen(26, false);
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            seen[c - 'a'] = true;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            seen[c - 'A'] = true;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (!seen[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
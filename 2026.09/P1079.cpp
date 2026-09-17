#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int val(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A';
    return ch - 'a';
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < (int)s2.size(); i++)
    {
        int c = val(s2[i]);
        int k = val(s1[i % s1.size()]);
        int m = (c - k + 26) % 26;

        if (s2[i] >= 'A' && s2[i] <= 'Z')
            cout << char(m + 'A');
        else
            cout << char(m + 'a');
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
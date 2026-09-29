#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int charToInt(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 10;
    if ('a' <= c && c <= 'z')
        return c - 'a' + 10;
    return -1;
}

ll parseBase(const string &num, int base)
{
    ll res = 0;
    for (char c : num)
    {
        int d = charToInt(c);
        if (d < 0 || d >= base)
            return -1;
        res = res * base + d;
    }
    return res;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    cout << parseBase(s, n) << '\n';
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
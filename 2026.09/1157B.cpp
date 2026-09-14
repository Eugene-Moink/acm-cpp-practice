#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int f[10];
    for (int i = 1; i <= 9; i++)
        cin >> f[i];

    int i = 0;
    while (i < n && f[s[i] - '0'] <= s[i] - '0')
        i++;

    while (i < n && f[s[i] - '0'] >= s[i] - '0')
    {
        s[i] = char('0' + f[s[i] - '0']);
        i++;
    }

    cout << s << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
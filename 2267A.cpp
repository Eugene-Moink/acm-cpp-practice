#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        int j = n - 1 - i;
        if (s[i] == s[j])
            continue;
        if (s[i] == c || s[j] == c)
            ans += 1;
        else
            ans += 2;
    }
    cout << ans << '\n';
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
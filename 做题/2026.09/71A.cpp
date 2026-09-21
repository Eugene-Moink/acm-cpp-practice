#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    if (s.size() <= 10)
    {
        cout << s << '\n';
        return;
    }

    else
    {
        cout << s[0] << s.size() - 2 << s.back() << '\n';
    }
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
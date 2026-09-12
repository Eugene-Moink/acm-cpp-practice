#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            ans ^= i;
            continue;
        }

        string s = to_string(i);
        int l = 0, r = (int)s.size() - 1;
        bool ok = 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                ok = 0;
                break;
            }
            l++, r--;
        }
        if (ok)
            ans ^= i;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
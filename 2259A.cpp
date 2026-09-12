#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i += k)
    {
        bool has_zero = false;
        for (int j = i; j < i + k; j++)
        {
            if (s[j] == '0')
            {
                has_zero = true;
                break;
            }
        }

        if (!has_zero)
            ans++;
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
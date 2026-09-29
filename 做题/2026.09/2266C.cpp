#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    if (s[0] == '1')
    {
        int cnt0 = 0;
        for (char c : s)
            if (c == '0')
                cnt0++;
        cout << cnt0 << '\n';
        return;
    }

    vector<int> pref1(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref1[i + 1] = pref1[i] + (s[i] == '1');
    }

    vector<int> suf0(n + 2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suf0[i] = suf0[i + 1] + (s[i] == '0');
    }

    int ans = INT_MAX;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, pref1[i] + suf0[i]);
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
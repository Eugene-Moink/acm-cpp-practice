#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    ll cnt1 = count(s.begin(), s.end(), '1');
    vector<int> cnt(n + 1, 0);
    while (m--)
    {
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }

    ll ans = cnt1;
    for (int i = 0; i < n; ++i)
    {
        if (cnt[i] != 0 && s[i] != '1')
            ans++;
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
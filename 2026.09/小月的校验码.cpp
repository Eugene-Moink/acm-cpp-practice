#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, b;
    cin >> n >> b;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int x = 0;
        for (char c : s)
            x = x * 2 + (c - '0');

        cnt[x]++;
    }

    ll ans = 0;
    vector<ll> diff(b, 0);
    for (auto &p : cnt)
    {
        int x = p.first;
        for (int i = 0; i < b; i++)
        {
            int y = x ^ (1 << b - i - 1);
            if (cnt.count(y))
            {
                ans += 1;
                diff[i]++;
            }
        }
    }

    cout << ans / 2 << '\n';
    for (int i = 0; i < b; i++)
    {
        cout << diff[i] / 2 << (i == b - 1 ? "\n" : " ");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
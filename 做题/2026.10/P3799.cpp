#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(5005, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    ll ans = 0;

    for (int x = 2; x <= 5000; x++)
    {
        if (cnt[x] < 2)
            continue;

        ll two_side = 1LL * cnt[x] * (cnt[x] - 1) / 2;

        for (int y = 1; y <= x / 2; y++)
        {
            int z = x - y;
            ll third_side = 0;

            if (y == z)
                third_side = 1LL * cnt[y] * (cnt[y] - 1) / 2;
            else
                third_side = 1LL * cnt[y] * cnt[z];

            ans = (ans + two_side * third_side) % MOD;
        }
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
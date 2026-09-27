#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int get_num(int x)
{
    int sum = 0;
    while (x > 0)
    {
        int d = x % 10;
        sum += d * d;
        x /= 10;
    }
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        for (int step = 0; step < 1000; step++)
        {
            val = get_num(val);
        }
        cnt[val]++;
    }

    ll ans = 0;
    for (auto &[entry, count] : cnt)
    {
        ans += 1LL * count * (count - 1) / 2;
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
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
#define pb push_back
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll part1 = n * k;
    lll part2 = 0;
    ll l = 1;
    while (l <= min(n, k))
    {
        ll v = k / l;
        ll r = min(n, k / v);

        lll cnt = r - l + 1;
        lll sum_lr = (lll)(l + r) * cnt / 2;
        part2 += v * sum_lr;

        l = r + 1;
    }
    ll ans = part1 - part2;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
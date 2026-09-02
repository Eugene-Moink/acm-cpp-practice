#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int cnt[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    ll ans = 0;
    ans += cnt[4];

    int m = min(cnt[3], cnt[1]);
    ans += m;
    cnt[3] -= m;
    cnt[1] -= m;
    ans += cnt[3];

    ans += cnt[2] / 2;
    if (cnt[2] % 2 == 1)
    {
        ans += 1;
        cnt[1] = max(0, cnt[1] - 2);
    }

    if (cnt[1] % 4 == 0)
        ans += cnt[1] / 4;
    else
        ans += (cnt[1] + 3) / 4;

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
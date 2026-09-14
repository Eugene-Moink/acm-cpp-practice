#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int N, K, S;
    cin >> N >> K >> S;

    ll ans = 0;
    int sc[305] = {0};
    int cnt[305] = {0};
    for (int i = 0; i < N; i++)
    {
        int t, p;
        cin >> t >> p;
        if (t >= 175 && p < S)
            sc[t]++;

        if (t >= 175 && p >= S)
            cnt[t]++;
    }

    for (int t = 175; t <= 290; t++)
    {
        ans += min(K, sc[t]) + (cnt[t]);
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll N, K;
    cin >> N >> K;

    ll ans = (N + K - 1) / K;

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
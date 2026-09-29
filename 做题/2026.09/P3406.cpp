#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> city(m);
    for (int &x : city)
        cin >> x;

    vector<ll> A(n + 1), B(n + 1), C(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<int> diff(n + 2, 0);
    for (int i = 0; i + 1 < m; i++)
    {
        int u = city[i], v = city[i + 1];
        if (u > v)
            swap(u, v);
        diff[u]++;
        diff[v]--;
    }

    ll ans = 0, cnt = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        cnt += diff[i];
        ans += min(cnt * A[i], C[i] + cnt * B[i]);
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
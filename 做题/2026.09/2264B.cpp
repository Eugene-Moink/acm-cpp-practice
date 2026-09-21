#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int tmp = INT_MIN;
    for (int &x : a)
    {
        cin >> x;
        tmp = max(tmp, x);
    }

    if (m == 1)
    {
        cout << tmp << '\n';
        return;
    }

    priority_queue<ll> pq;
    ll sum = 0;
    ll ans = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        if ((ll)pq.size() == m - 1)
            ans = max(ans, (ll)m * a[i] - sum);

        pq.push(a[i]);
        sum += a[i];
        if ((ll)pq.size() > m - 1)
        {
            sum -= pq.top();
            pq.pop();
        }
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    vector<ll> diff(n + 2, 0);
    diff[1] = a[0];
    for (int i = 2; i <= n; i++)
    {
        diff[i] = a[i - 1] - a[i - 2];
    }
    diff[n + 1] = -a[n - 1];

    ll sum = 0, neg_sum = 0;
    for (int i = 2; i <= n; i++)
    {
        if (diff[i] > 0)
            sum += diff[i];
        else
            neg_sum += abs(diff[i]);
    }

    ll ans_1 = max(sum, neg_sum);
    ll ans_2 = abs(sum - neg_sum) + 1;
    cout << ans_1 << '\n'
         << ans_2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
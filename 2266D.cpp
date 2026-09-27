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

    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] - i;
    }

    sort(b.begin(), b.end());
    int len = 1, ans = 1;
    ll cur = b[0];
    for (int i = 1; i < n; i++)
    {
        if (b[i] == cur)
            continue;
        if (b[i] == cur + 1)
        {
            len++;
        }
        else
        {
            ans = max(ans, len);
            len = 1;
        }
        cur = b[i];
    }
    ans = max(ans, len);
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
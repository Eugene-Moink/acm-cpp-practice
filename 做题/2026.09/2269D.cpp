#include <bits/stdc++.h>
using namespace std;

bool even_ones(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt % 2 == 0;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (even_ones(a[i]))
            ans++;
    }

    cout << ans << ' ';

    while (q--)
    {
        int p, x;
        cin >> p >> x;
        p--;
        if (even_ones(a[p]))
            ans--;
        a[p] = x;
        if (even_ones(a[p]))
            ans++;
        cout << ans << ' ';
    }
    cout << '\n';
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    int lo = 1, hi = -1;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
        hi = max(hi, x);
    }

    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        ll cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += a[i] / mid;

        if (cnt >= k)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
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
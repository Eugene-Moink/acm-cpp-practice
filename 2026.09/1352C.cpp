#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    ll l = 1, r = 2e9;

    while (l < r)
    {
        ll mid = (l + r) / 2;
        ll cnt = mid - mid / n;

        if (cnt >= k)
        {
            r = mid;
        }

        else
        {
            l = mid + 1;
        }
    }

    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
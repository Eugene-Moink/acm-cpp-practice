#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    ll m = 0;
    for (int i = 1; i <= n; i++)
    {
        m ^= i;
    }

    ll k = 1;
    while (k <= n)
        k <<= 1;
    k--;

    ll tar = 2 * k;
    vector<int> ans(n + 1, 0);

    for (int i = n; i >= 1; i--)
    {
        if (m > tar)
            break;

        ll new_m = m ^ i ^ (2LL * i);

        if (new_m > m)
        {
            m = new_m;
            ans[i] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
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
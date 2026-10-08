#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, c;
    cin >> n >> c;

    vector<ll> a(n);
    for (ll &x : a)
    {
        cin >> x;
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    int i = 0, j = 0;

    while (i < n)
    {
        int cntB = 1;
        while (i + cntB < n && a[i + cntB] == a[i])
            cntB++;

        ll target = a[i] + c;

        while (j < n && a[j] < target)
            j++;

        if (j < n && a[j] == target)
        {
            int cntA = 0;
            while (j < n && a[j] == target)
            {
                cntA++;
                j++;
            }
            ans += 1LL * cntB * cntA;
        }

        i += cntB;
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.rbegin(), a.rend());
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i - 1];

    while (q--)
    {
        int cur;
        cin >> cur;
        if (cur > pref[n])
        {
            cout << -1 << '\n';
            continue;
        }
        int idx = lower_bound(pref.begin(), pref.end(), cur) - pref.begin();
        cout << idx << '\n';
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
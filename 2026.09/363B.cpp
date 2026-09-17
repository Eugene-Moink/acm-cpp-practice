#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int ans = 0;
    int cur = INT_MAX;
    for (int i = 0; i + k <= n; i++)
    {
        int tmp = pref[i + k] - pref[i];
        if (tmp < cur)
        {
            cur = tmp;
            ans = i;
        }
    }
    cout << ans + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
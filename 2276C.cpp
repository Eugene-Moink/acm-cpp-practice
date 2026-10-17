#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = (pref[i - 1] + a[i - 1]) % k;

    ll ans = 0;
    int l = 0;
    vector<int> cnt(k, 0);
    for (int j = 1; j <= n; j++)
    {
        while (l < j - k)
        {
            cnt[pref[l]]++;
            l++;
        }
        ans += cnt[pref[j]];
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
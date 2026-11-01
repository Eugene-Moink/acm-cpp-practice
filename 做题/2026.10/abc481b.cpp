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
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == k)
            ans++;
        else if ((a[i] < k && a[i + 1] > k) || (a[i] > k && a[i + 1] < k))
            ans++;
    }
    if (a[n - 1] == k)
        ans++;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
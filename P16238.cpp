#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), diff(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        diff[i] = b[i] - a[i];
        tmp += diff[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        diff[i] += tmp / n;
        if (diff[i] == 0)
            ans++;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
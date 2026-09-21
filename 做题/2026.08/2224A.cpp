#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i + 1] > 0)
            a[i] += a[i + 1];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] > 0)
            ans++;

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        moink();

    return 0;
}
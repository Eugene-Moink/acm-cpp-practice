#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, k;
    cin >> n >> k;
    vector<int> pref(n + 1, 0);
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        pref[i] = pref[i - 1] + p[i - 1];
    }

    double ans = -1.0;
    for (int i = 0; i + k <= n; ++i)
    {
        ans = max(ans, (pref[i + k] - pref[i] + k) / 2.0);
    }
    cout << fixed << setprecision(10) << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
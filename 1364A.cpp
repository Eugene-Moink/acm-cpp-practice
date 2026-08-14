#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % x != 0)
    {
        cout << n << '\n';
        return;
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int left = -1, right = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (pref[i] % x != 0)
        {
            left = i;
            break;
        }
    }

    for (int i = n - 1; i >= 1; --i)
    {
        if (pref[i] % x != 0)
        {
            right = i;
            break;
        }
    }

    if (left == -1 && right == -1)
    {
        cout << -1 << '\n';
    }
    else
    {
        int ans = 0;
        if (left != 0)
            ans = max(ans, n - left);
        if (right != 0)
            ans = max(ans, right);

        cout << ans << '\n';
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
        moink();
    }
    return 0;
}
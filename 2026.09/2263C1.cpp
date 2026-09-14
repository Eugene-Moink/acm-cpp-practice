#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> diff(n + 2, 0);

    for (int k = 1; k <= n; k++)
    {
        long long L = 1LL * a[k] * k;
        long long R = 1LL * (a[k] + 1) * k - 1;

        if (L >= n)
        {
            continue;
        }

        L = max(L, 0LL);
        R = min(R, (long long)n - 1);

        if (L <= R)
        {
            diff[L]++;
            diff[R + 1]--;
        }
    }

    vector<int> B;
    int cur = 0;

    for (int i = 0; i < n; i++)
    {
        cur += diff[i];
        if (cur == 0)
        {
            B.push_back(i);
        }
    }

    cout << B.size() << '\n';

    for (int i = 0; i < (int)B.size(); i++)
    {
        if (i > 0)
        {
            cout << ' ';
        }
        cout << B[i];
    }
    cout << '\n';
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n), b(n), c(n, 0);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            cout << -1 << '\n';
            return;
        }

        else if (a[i] == b[i])
            c[i] = 0;

        else if (a[i] == 0 && b[i] > 0)
        {
            cout << -1 << '\n';
            return;
        }

        else if (b[i] == M)
        {
            ll cur = a[i];
            int cnt = 0;
            while (cur < M)
            {
                cur *= 2;
                cnt++;
            }
            c[i] = cnt;
        }

        else
        {
            if (b[i] % a[i] != 0)
            {
                cout << -1 << '\n';
                return;
            }
            ll q = b[i] / a[i];

            if ((q & (q - 1)) != 0)
            {
                cout << -1 << '\n';
                return;
            }
            c[i] = __builtin_ctzll(q);
        }
    }

    ll ans = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur < c[i])
        {
            ans += c[i] - cur;
            cur = c[i];
        }
        if (b[i] < M && a[i] != 0 && cur > c[i])
        {
            cur = c[i];
        }
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
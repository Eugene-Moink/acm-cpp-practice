#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    vector<ll> w(n, 1);
    w[pos] = (ll)1e18;

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << ' ';
        cout << w[i];
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
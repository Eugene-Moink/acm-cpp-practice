#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll k = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] > a[i])
        {
            k = max(k, a[i - 1] - a[i]);
        }
    }

    if (k == 0)
    {
        cout << "YES\n";
        return;
    }

    vector<ll> b = a;
    for (int i = 1; i < n; ++i)
    {
        if (b[i - 1] > b[i])
        {
            b[i] += k;
        }
    }

    bool ok = true;
    for (int i = 1; i < n; ++i)
    {
        if (b[i - 1] > b[i])
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    int cntMax = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (a[i] == a[n - 1])
            ++cntMax;
        else
            break;
    }

    if (k < cntMax)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    int p = n - k;
    for (int i = p; i < n; ++i)
    {
        cout << a[i] << " ";
    }

    for (int i = p - 1; i >= 0; --i)
    {
        cout << a[i] << " ";
    }

    cout << "\n";
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
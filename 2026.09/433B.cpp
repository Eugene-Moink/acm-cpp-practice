#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());

    vector<ll> pref1(n + 1, 0), pref2(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pref1[i] = pref1[i - 1] + a[i - 1];
        pref2[i] = pref2[i - 1] + b[i - 1];
    }

    int m;
    cin >> m;
    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            cout << pref1[r] - pref1[l - 1] << '\n';
        }
        else
        {
            cout << pref2[r] - pref2[l - 1] << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
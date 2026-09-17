#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> n1(n), n2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> n1[i];
        n2[i] = n1[i];
    }

    sort(n2.begin(), n2.end());
    vector<ll> pref1(n + 1, 0), pref2(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref1[i] = pref1[i - 1] + n1[i - 1];
        pref2[i] = pref2[i - 1] + n2[i - 1];
    }

    int m;
    cin >> m;
    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            cout << pref1[r] - pref1[l - 1] << '\n';
        else
            cout << pref2[r] - pref2[l - 1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
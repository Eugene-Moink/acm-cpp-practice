#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> a_sort;
    a_sort = a;
    sort(a_sort.begin(), a_sort.end());
    vector<ll> pref1(n + 1, 0), pref2(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        pref1[i] = pref1[i - 1] + a[i - 1];
        pref2[i] = pref2[i - 1] + a_sort[i - 1];
    }

    int m;
    cin >> m;
    while (m--)
    {
        int i, l, r;
        cin >> i >> l >> r;
        if (i == 1)
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
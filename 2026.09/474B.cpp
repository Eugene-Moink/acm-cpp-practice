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

    int m;
    cin >> m;
    vector<int> b(m);
    for (int &x : b)
        cin >> x;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i - 1];

    for (int q : b)
    {
        int pos = lower_bound(pref.begin() + 1, pref.end(), q) - pref.begin();
        cout << pos << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
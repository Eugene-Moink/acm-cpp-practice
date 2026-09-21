#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i - 1];

    int m;
    cin >> m;
    while (m--)
    {
        int tmp;
        cin >> tmp;
        int pos = lower_bound(pref.begin(), pref.end(), tmp) - pref.begin();
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
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

    vector<int> nxt(n, -1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] != a[i + 1])
            nxt[i] = i + 1;
        else
            nxt[i] = nxt[i + 1];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (nxt[l] != -1 && nxt[l] <= r)
            cout << l + 1 << ' ' << nxt[l] + 1 << '\n';
        else
            cout << "-1 -1\n";
    }
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
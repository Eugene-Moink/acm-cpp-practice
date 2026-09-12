#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
    {
        cin >> x;
    }

    b[0] = a[0];
    for (int i = 1; i <= n; i++)
    {
        b[i] = min(b[i - 1], a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << b[i] << ((i == n - 1 ? '\n' : ' '));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
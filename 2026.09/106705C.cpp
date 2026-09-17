#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> pos(n), t(n);
    for (ll &x : pos)
        cin >> x;
    for (ll &x : t)
        cin >> x;

    for (int i = 0; i < n; i++)
    {
        int tmp = max(pos[i] - pos[0], pos[n - 1] - pos[i]) * 2;
        if (t[i] < tmp)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
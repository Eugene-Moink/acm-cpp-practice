#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m;
    string s;
    cin >> n >> m >> s;
    if (m >= 50 || m >= n * 0.2)
    {
        cout << "YES\n";
        return;
    }
    int t = stoi(s.substr(0, 2));
    if (t >= 4)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    cout << n * (n - 1) * 1LL << endl;
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
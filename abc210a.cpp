#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, a, x, y;
    cin >> n >> a >> x >> y;
    if (n <= a)
        cout << n * x * 1LL << '\n';
    else
    {
        ll ans = a * x * 1LL + (n - a) * y;
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
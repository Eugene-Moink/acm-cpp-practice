#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = (4 * a + 3 * b + 11) / 12;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int x, y, n;
    cin >> x >> y >> n;
    if (n % 2 == 1)
    {
        int t1 = n * x;
        int t2 = (n / 2) * y * 2 + x;
        int ans = min(t1, t2);
        cout << ans;
    }
    else
    {
        int t1 = n * x;
        int t2 = (n / 2) * y * 2;
        int ans = min(t1, t2);
        cout << ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
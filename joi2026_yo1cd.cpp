#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        for (int j = 0; j < m; j++)
        {
            int h;
            cin >> h;
            tmp = max(h, tmp);
        }
        ans += tmp;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
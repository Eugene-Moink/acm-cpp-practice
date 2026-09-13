#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
    {
        if (a == b && b == c)
        {
            cout << -1;
            return;
        }
        int na = (b + c) / 2;
        int nb = (a + c) / 2;
        int nc = (a + b) / 2;
        a = na, b = nb, c = nc;
        cnt++;
    }
    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
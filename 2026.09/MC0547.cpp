#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int c1 = 0, c2 = 0;
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (y >= x)
            c1++;
        else
            c2++;
    }
    cout << c1 << ' ' << c2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, x, y, z;
    int sumx = 0, sumy = 0, sumz = 0;
    cin >> n;
    while (n--)
    {
        cin >> x >> y >> z;
        sumx += x;
        sumy += y;
        sumz += z;
    }
    if (sumx == 0 && sumy == 0 && sumz == 0)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int c2 = 0, c3 = 0, c5 = 0;
    while (n--)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            c2 += x;
        else if (x % 3 == 0)
            c3 += x;
        else if (x % 5 == 0)
            c5 += x;
    }
    cout << c2 << ' ' << c3 << ' ' << c5 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
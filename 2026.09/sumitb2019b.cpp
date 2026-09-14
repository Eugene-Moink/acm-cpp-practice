#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i * 108 / 100 == n)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << ":(" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
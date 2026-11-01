#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        char c = (i % 2 != 0) ? '+' : '-';
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << c;
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
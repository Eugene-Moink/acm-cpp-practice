#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    if (n == 1 || n == 2)
    {
        cout << "No\n";
        return;
    }

    else
    {
        cout << "Yes" << '\n';
        cout << 152;
        for (int i = 1; i <= n - 3; i++)
            cout << 0;

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
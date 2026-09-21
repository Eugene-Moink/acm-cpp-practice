#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a = -1, b = -1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            a = i;
            n /= i;
            break;
        }
    }
    if (a == -1)
    {
        cout << "NO\n";
        return;
    }

    for (int i = a + 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            b = i;
            n /= i;
            break;
        }
    }
    if (b == -1)
    {
        cout << "NO\n";
        return;
    }

    int c = n;
    if (c < 2 || c == a || c == b)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n"
         << a << ' ' << b << ' ' << c << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
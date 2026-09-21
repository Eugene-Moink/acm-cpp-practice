#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int d;
    cin >> d;

    if (d == 0)
    {
        cout << "Y 0.000000000 0.000000000" << '\n';
        return;
    }
    if (d == 1 || d == 2 || d == 3)
    {
        cout << 'N' << '\n';
        return;
    }

    double delta = d * d - 4 * d;
    double a = (d + sqrt(delta)) / 2, b = (d - sqrt(delta)) / 2;
    cout << "Y " << fixed << setprecision(9)
         << a << ' ' << b << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
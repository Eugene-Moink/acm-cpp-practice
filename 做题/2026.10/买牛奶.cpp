#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b;
    cin >> a >> b;

    for (int day = 1; day <= 6; day++)
    {
        ll discount;
        if (day <= 2)
        {
            discount = 10;
        }

        else
        {
            discount = 12 - day;
        }

        if (b * 10 >= a * discount)
        {
            cout << day << " " << fixed << setprecision(2) << (a * discount) / 10.0 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
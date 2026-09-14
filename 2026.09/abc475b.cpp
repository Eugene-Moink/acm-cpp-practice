#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    ll cnt1 = 0, cnt10 = 0, cnt100 = 0;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;

        ll bills = (a + 999) / 1000;
        ll pay = bills * 1000;
        ll change = pay - a;

        cnt100 += change / 100;
        change %= 100;

        cnt10 += change / 10;
        change %= 10;

        cnt1 += change;
    }

    cout << cnt1 << ' ' << cnt10 << ' ' << cnt100 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
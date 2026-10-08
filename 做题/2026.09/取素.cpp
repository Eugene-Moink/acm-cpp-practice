#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    ll cnt = 0;
    for (ll i = 2; i <= n / i; i++)
    {
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
    }
    if (n > 1)
        cnt++;

    cout << (cnt % 2 ? "kou" : "yukari") << '\n';
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (n % 2 != 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << 1 << ' ' << -1 << ' ' << n / 2 << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, a;
    cin >> n >> m >> a;

    ll x = (n + a - 1) / a;
    ll y = (m + a - 1) / a;

    cout << x * y << '\n';
    return 0;
}
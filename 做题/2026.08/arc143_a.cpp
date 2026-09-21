#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll val_max = max({a, b, c});
    ll sum = a + b + c;

    if (val_max > sum - val_max)
        cout << -1;

    else
    {
        cout << (max(sum / 3, val_max)) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll k;
    cin >> k;
    ll ans = 0;
    for (ll i = 1; i <= k; ++i)
    {
        for (ll j = 1; i * j <= k; ++j)
        {
            ans += k / (i * j);
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
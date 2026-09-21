#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n;
    cin >> n;

    int len = 0;
    ll tmp = n;
    while (tmp > 0)
    {
        len++;
        tmp >>= 1;
    }

    ll ans = (1LL << len) - 1;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n, m;
    cin >> n >> m;
    ll min_val = min(n, m);

    ll ans;
    if (n == m)
        ans = min_val * 2;
    else
        ans = min_val * 2 + 1;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
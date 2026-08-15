#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n, a, b;
    cin >> n >> a >> b;

    if (a > b)
    {
        cout << 0 << '\n';
        return;
    }

    ll min_sum = a * (n - 1) + b;
    ll max_sum = a + (n - 1) * b;
    ll ans = max(0LL, max_sum - min_sum + 1);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
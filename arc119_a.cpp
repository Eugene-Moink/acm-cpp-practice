#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll N;
    cin >> N;
    ll ans = N;

    for (ll b = 0; b <= 60; b++)
    {
        ll pow2 = 1LL << b;
        if (pow2 > N)
            break;
        ll a = N / pow2;
        ll c = N - a * pow2;
        ans = min(ans, a + b + c);
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
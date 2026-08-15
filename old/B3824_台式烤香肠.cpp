#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll d, e, f;
    cin >> d >> e >> f;

    ll k;
    cin >> k;

    ll num_1 = k / b * c * a;
    ll num_2 = k / e * f * d;

    ll ans = max(num_1, num_2);
    cout << ans << endl;
    return 0;
}
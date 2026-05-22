#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll result_1 = 0;
    ll result_2 = 0;

    ll Sn = n * (n + 1) / 2;
    ll Sm = m * (m + 1) / 2;
    result_2 = Sn * Sm;

    for (ll k = 1; k <= min(m, n);k++)
    {
        ll temp_1 = (n - k + 1) * (m - k + 1);
        result_1 += temp_1;
    }

    cout << result_1 << " " << result_2-result_1 << endl;
    return 0;
}

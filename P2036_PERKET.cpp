#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<ll> s(n), b(n);
    for (int i = 0; i < n;i++)
    {
        cin >> s[i] >> b[i];
    }

    ll ans = LLONG_MAX;
    for (int mask = 1; mask < (1 << n);mask++)
    {
        ll prod = 1;
        ll sum = 0;

        for (int i = 0; i < n;i++)
        {
            if(mask&(1<<i))
            {
                prod *= s[i];
                sum += b[i];
            }
        }
        ans = min(ans, llabs(prod - sum));
    }
    cout << ans << endl;
    return 0;
}
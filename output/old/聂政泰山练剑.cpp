#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1), sum(n + 1, 0);
    for (ll i = 1; i <= n;i++)
    {
        cin >> a[i];
        sum[i] += sum[i - 1] + a[i];
    }

    ll ans = 0;
    for (ll i = 1; i <= n;i++)
    {
        for (ll j = i; j <= n;j++)
        {
            ll sub_sum = sum[j] - sum[i - 1];
            ans += __builtin_popcountll(sub_sum);
        }
    }

    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
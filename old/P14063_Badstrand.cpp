#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll N, B;
    cin >> N >> B;
    vector<ll> price(N);
    vector<ll> pref(N + 1, 0);
    for (ll i = 0; i < N;i++)
    {
        cin >> price[i];
        pref[i + 1] = pref[i] + price[i];
    }

    ll max_len = 0;
    for (ll r = 0; r < N;r++)
    {

        ll target = pref[r + 1] - B;
        auto it = lower_bound(pref.begin(), pref.begin() + r + 1, target);
        if (it != pref.begin() + r + 1)
        {
            ll l = it - pref.begin();
            ll len = r - l + 1;
            max_len = max(max_len, len);
        }
    }
    cout << max_len << endl;
}

int main()
{
    moink();
    return 0;
}
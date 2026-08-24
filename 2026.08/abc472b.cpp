#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    ll diff = LLONG_MAX;
    for (int i = 1; i <= n; ++i)
    {
        diff = min(diff, abs(pref[i] - (sum - pref[i])));
    }
    cout << diff;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink() 
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<ll> a(x), b(y);
    for (auto &v : a) cin >> v;
    for (auto &v : b) cin >> v;

    ll ans = 0;

    int take = min(x, n);
    ll sum = 0;
    for (int i = x - take; i < x; i++) sum += a[i];
    ans = max(ans, sum);

    take = min(y, m);
    sum = 0;
    for (int i = y - take; i < y; i++) sum += b[i];
    ans = max(ans, sum);


    int take_a = min(x, n - 1);
    int take_b = min(y, m);
    if (take_a > 0 && take_b > 0) {
        set<ll> st;
        for (int i = x - take_a; i < x; i++) st.insert(a[i]);
        for (int i = y - take_b; i < y; i++) st.insert(b[i]);
        sum = 0;
        for (ll v : st) sum += v;
        ans = max(ans, sum);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
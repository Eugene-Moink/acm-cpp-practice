#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> get_factors(int n)
{
    vector<int> fac;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            fac.push_back(i);
            if (i != n / i)
                fac.push_back(n / i);
        }
    }
    sort(fac.begin(), fac.end());
    return fac;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &v : a)
        cin >> v;

    vector<int> fac = get_factors(x);

    ll ans = 0;
    for (int d : fac)
    {
        if (d == 1)
            continue;
        ll sum = 0;
        for (int v : a)
        {
            if (v % d == 0)
                sum += v;
        }
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
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(double t, vector<int> &a, vector<int> &b, double p)
{
    double need = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        double cost = a[i] * t;
        if (cost > b[i])
        {
            need += cost - b[i];
            if (need > p * t)
                return false;
        }
    }
    return need <= p * t;
}

void solve()
{
    int n, p;
    cin >> n >> p;

    double sum_a = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        sum_a += a[i];
    }

    if (sum_a <= p)
    {
        cout << -1;
        return;
    }

    double lo = 0, hi = 1e10;
    for (int i = 0; i < 100; i++)
    {
        double mid = (lo + hi) / 2;
        if (check(mid, a, b, p))
            lo = mid;
        else
            hi = mid;
    }
    cout << fixed << setprecision(10) << lo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
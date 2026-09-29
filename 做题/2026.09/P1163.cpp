#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double w0, w;
int m;

bool check(double mid)
{
    double total = 0;
    if (mid < 1e-8)
        total = w * m;
    else
        total = w * (1.0 - pow(1.0 + mid, -m)) / mid;
    return total >= w0;
}

void solve()
{
    cin >> w0 >> w >> m;
    double l = 0.0, r = 3.0;
    for (int i = 0; i < 50; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(1) << l * 100 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }

    sort(a.begin(), a.end());

    vector<double> dist;
    dist.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        dist.push_back((a[i] - a[i - 1]) * 0.5);
    }
    dist.push_back(l - a[n - 1]);

    double max_dist = -1;
    for (double x : dist)
    {
        max_dist = max(max_dist, x);
    }

    cout << fixed << setprecision(10) << max_dist << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
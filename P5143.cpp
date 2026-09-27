#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point
{
    ll x, y, z;
    bool operator<(const point &other) const
    {
        return z < other.z;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    sort(p.begin(), p.end());

    double dist = 0.0;
    for (int i = 1; i < n; i++)
    {
        dist += sqrt((double)(p[i].x - p[i - 1].x) * (p[i].x - p[i - 1].x) +
                     (double)(p[i].y - p[i - 1].y) * (p[i].y - p[i - 1].y) +
                     (double)(p[i].z - p[i - 1].z) * (p[i].z - p[i - 1].z));
    }
    cout << fixed << setprecision(3) << dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
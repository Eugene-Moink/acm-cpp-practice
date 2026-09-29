#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> rects;
    vector<int> xs, ys;

    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 < y2)
            swap(y1, y2);
        rects.emplace_back(x1, y1, x2, y2);
        xs.push_back(x1);
        xs.push_back(x2);
        ys.push_back(y1);
        ys.push_back(y2);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int nx = xs.size(), ny = ys.size();
    vector<vector<bool>> cover(nx, vector<bool>(ny, false));

    for (auto [x1, y1, x2, y2] : rects)
    {
        int lx = lower_bound(xs.begin(), xs.end(), x1) - xs.begin();
        int rx = lower_bound(xs.begin(), xs.end(), x2) - xs.begin();
        int ly = lower_bound(ys.begin(), ys.end(), y2) - ys.begin();
        int ry = lower_bound(ys.begin(), ys.end(), y1) - ys.begin();
        for (int i = lx; i < rx; i++)
            for (int j = ly; j < ry; j++)
                cover[i][j] = true;
    }

    ll ans = 0;
    for (int i = 0; i < nx - 1; i++)
        for (int j = 0; j < ny - 1; j++)
            if (cover[i][j])
                ans += 1LL * (xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]);

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
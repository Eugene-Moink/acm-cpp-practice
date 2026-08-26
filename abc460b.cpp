#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    ll dx = x1 - x2;
    ll dy = y1 - y2;
    ll dist = (1LL * dx * dx + 1LL * dy * dy);

    if (dist >= (r1 - r2) * (r1 - r2) && dist <= (r1 + r2) * (r1 + r2))
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    ll sum_v = 0;
    ll sum_w = 0;
    for (int i = 0; i < n; i++)
    {
        ll v;
        cin >> v;
        sum_v += v;
    }
    for (int i = 0; i < n; i++)
    {
        ll w;
        cin >> w;
        sum_w += w;
    }
    double ans = (double)sum_w / sum_v;
    cout << fixed << setprecision(6) << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<int> &a, int l, int mid, int m)
{
    int last = 0;
    int move = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] - last < mid)
            move++;
        else
            last = a[i];
    }
    if (l - last < mid)
    {
        move++;

        // reture false;
    }
    return move <= m;
}

void solve()
{
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int lo = 0, hi = l;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(a, l, mid, m))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
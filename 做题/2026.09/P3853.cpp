#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<int> &a, int l, int mid, int k)
{
    int add = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        int diff = a[i] - a[i - 1];
        if (diff > mid)
        {
            add += (diff - 1) / mid;
            if (add > k)
                return false;
        }
    }
    return add <= k;
}

void solve()
{
    int l, n, k;
    cin >> l >> n >> k;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int lo = 1, hi = l;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(a, l, mid, k))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
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
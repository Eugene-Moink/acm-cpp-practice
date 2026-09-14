#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt0 = 0;
    for (int &x : a)
    {
        cin >> x;
        if (x == 0)
            cnt0++;
    }

    int ans;
    if (cnt0 == 0)
    {
        ans = -1;
    }
    else if (cnt0 == 1)
    {
        ans = (n == 1 && a[0] == 0) ? 0 : -1;
    }
    else
    {

        int border = (a[0] == 0) + (a[n - 1] == 0);
        ans = 2 - border;
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
    {
        solve();
    }
    return 0;
}
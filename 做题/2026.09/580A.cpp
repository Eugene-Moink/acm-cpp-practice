#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int ans = 1;
    int cur = a[0], cnt = 1;
    for (int i = 1; i <= n - 1; ++i)
    {
        int tmp = a[i];
        if (cur <= tmp)
            cnt++;

        else if (cur > tmp)
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
        cur = a[i];
    }
    ans = max(ans, cnt);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int &x : num)
        cin >> x;

    int cur = num[0];
    int ans = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        int tmp = num[i];
        if (cur <= tmp)
            cnt++;
        else
        {
            ans = max(cnt, ans);
            cnt = 1;
        }
        cur = num[i];
    }
    ans = max(cnt, ans);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
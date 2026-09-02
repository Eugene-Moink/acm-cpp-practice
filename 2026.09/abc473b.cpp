#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int cnt[105] = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            ans += i;
        }
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
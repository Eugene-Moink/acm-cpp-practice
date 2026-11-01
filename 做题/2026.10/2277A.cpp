#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, k;
    cin >> n >> k;
    int cnt[105] = {0};

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            cout << i << '\n';
            return;
        }

        sum += cnt[i];
        if (sum >= k)
        {
            sum -= k;
        }
        else
        {
            cout << i << '\n';
            return;
        }
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt[1000005];
int vis[1000005];

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }

    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        int max_cnt = 0;

        for (int i = l - 1; i <= r; i++)
        {
            int x = a[i];
            if (vis[x] != i)
            {
                vis[x] = i;
                cnt[x] = 1;
            }
            else
                cnt[x]++;

            max_cnt = max(cnt[x], max_cnt);
        }
        cout << max_cnt << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
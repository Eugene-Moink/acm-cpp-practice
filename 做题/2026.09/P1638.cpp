#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> cnt(m + 1, 0);
    int kind = 0;
    int l = 1;

    int best_len = INT_MAX;
    int best_l = -1, best_r = -1;

    for (int r = 1; r <= n; r++)
    {
        if (cnt[a[r]] == 0)
            kind++;
        cnt[a[r]]++;

        while (kind == m)
        {
            int len = r - l + 1;
            if (len < best_len || (len == best_len && l < best_l))
            {
                best_len = len;
                best_l = l;
                best_r = r;
            }

            cnt[a[l]]--;
            if (cnt[a[l]] == 0)
                kind--;
            l++;
        }
    }

    cout << best_l << ' ' << best_r << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
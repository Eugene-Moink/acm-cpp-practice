#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int val_max = 0;
    for (int &x : a)
    {
        cin >> x;
        val_max = max(val_max, x);
    }

    vector<int> freq(val_max + 1, 0);
    for (int &x : a)
    {
        freq[x]++;
    }

    vector<int> cnt(val_max + 1, 0);
    for (int d = 1; d <= val_max; d++)
    {
        for (int m = d; m <= val_max; m += d)
            cnt[d] += freq[m];
    }

    vector<int> ans(n + 1, 0);
    int max_k = 0;
    for (int d = val_max; d >= 1; d--)
    {
        if (cnt[d] > max_k)
        {
            for (int k = max_k + 1; k <= cnt[d]; k++)
            {
                ans[k] = d;
            }
            max_k = cnt[d];
        }
        if (max_k == n)
            break;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
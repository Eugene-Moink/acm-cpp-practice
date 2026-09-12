#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int max_val = -1, min_val = INT_MAX;
        for (int j = i; j < n; j++)
        {
            max_val = max(max_val, a[j]);
            min_val = min(min_val, a[j]);
            if (abs(max_val - min_val) <= k)
            {
                ans++;
            }
            else
                break;
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
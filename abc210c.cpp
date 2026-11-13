#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int diff = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < k; i++)
    {
        if (cnt[a[i]] == 0)
            diff++;
        cnt[a[i]]++;
    }

    int ans = diff;
    for (int i = k; i < n; i++)
    {
        if (cnt[a[i]] == 0)
            diff++;
        cnt[a[i]]++;

        int last_color = a[i - k];
        cnt[last_color]--;
        if (cnt[last_color] == 0)
            diff--;

        ans = max(ans, diff);
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
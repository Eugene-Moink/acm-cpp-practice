#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> high(n);
    for (int &x : high)
        cin >> x;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + high[i - 1];

    int pos = 0;
    int ans = INT_MAX;
    for (int i = 0; i + k <= n; i++)
    {
        int tmp = pref[i + k] - pref[i];
        if (tmp < ans)
        {
            ans = tmp;
            pos = i;
        }
    }
    cout << pos + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
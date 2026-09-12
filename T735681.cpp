#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    vector<int> cnt(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        int cur_state = (s[i - 1] - '0') ^ (cnt[i] & 1);

        if (cur_state == 0)
        {
            ans++;
            for (int j = i; j <= n; j += i)
            {
                cnt[j]++;
            }
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
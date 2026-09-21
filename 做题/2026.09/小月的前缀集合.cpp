#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int q;
    cin >> q;
    map<string, int> cnt;
    ll ans = 0;
    while (q--)
    {
        char c;
        string s;
        cin >> c >> s;
        if (c == '+')
        {
            for (int i = 1; i <= s.size(); i++)
            {
                string tmp = s.substr(0, i);
                cnt[tmp]++;
                if (cnt[tmp] == 1)
                    ans++;
            }
        }
        else
        {
            for (int i = 1; i <= s.size(); i++)
            {
                string tmp = s.substr(0, i);
                cnt[tmp]--;
                if (cnt[tmp] == 0)
                    ans--;
            }
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
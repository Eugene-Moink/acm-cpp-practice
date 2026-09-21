#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
        int target = 0;
        for (int j = 0; j <= i; j++)
            target += s[j] - '0';

        int cur = 0, seg = 1;
        bool ok = 1;
        for (int k = i + 1; k < n; k++)
        {
            cur += s[k] - '0';
            if (cur == target)
            {
                seg++;
                cur = 0;
            }
            else if (cur > target)
            {
                ok = false;
                break;
            }
        }
        if (ok && cur == 0 && seg >= 2)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
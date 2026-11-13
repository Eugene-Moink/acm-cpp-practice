#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    bool need[26] = {false};

    for (int i = 0; i < n / 2; i++)
    {
        char left = s[i];
        char right = s[n - 1 - i];

        if (left != right)
        {
            char mx = max(left, right);
            char mn = min(left, right);

            for (char c = mn + 1; c <= mx; c++)
            {
                need[c - 'a'] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (need[i])
            ans++;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == 'R' && s[i + 1] == 'L')
        {
            int left = 0;
            int pos = i;
            while (pos >= 0 && s[pos] == 'R')
            {
                left++;
                pos--;
            }
            int right = 0;
            pos = i + 1;
            while (pos < n && s[pos] == 'L')
            {
                right++;
                pos++;
            }
            ans[i] = (left + 1) / 2 + right / 2;
            ans[i + 1] = left / 2 + (right + 1) / 2;
        }
    }
    for (int x : ans)
    {
        cout << x << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
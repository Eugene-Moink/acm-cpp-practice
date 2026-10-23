#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int first_pos = -1;
    int last_pos = -1;
    int cnt1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            cnt1++;
            if (first_pos == -1)
                first_pos = i;
            last_pos = i;
        }
    }

    if (cnt1 == 1)
    {
        cout << 0 << '\n';
    }
    else if (cnt1 == 2)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << last_pos - first_pos << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
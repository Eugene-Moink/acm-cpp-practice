#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (n == 1)
    {
        if (k >= 1)
            cout << "0\n";
        else
            cout << s << '\n';
        return;
    }

    for (int i = 0; i < n && k > 0; i++)
    {
        if (i == 0)
        {
            if (s[i] != '1')
            {
                s[i] = '1';
                k--;
            }
        }
        else
        {
            if (s[i] != '0')
            {
                s[i] = '0';
                k--;
            }
        }
    }

    cout << s << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
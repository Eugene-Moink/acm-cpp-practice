#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;

    int border = 0;
    for (int len = n - 1; len >= 1; len--)
    {
        if (t.substr(0, len) == t.substr(n - len))
        {
            border = len;
            break;
        }
    }

    string ans = t;
    for (int i = 1; i < k; i++)
    {
        ans += t.substr(border);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
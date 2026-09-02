#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0 && s[i] == '9')
        {
            cout << '9';
            continue;
        }

        if (s[i] >= '5')
        {
            cout << (char)('9' - s[i] + '0');
        }
        else
        {
            cout << s[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    cin >> s;
    string ans = "";
    for (char c : s)
    {
        if (c == '0' || c == '1')
        {
            ans.push_back(c);
        }

        else if (c == 'B')
        {
            if (!ans.empty())
                ans.pop_back();
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
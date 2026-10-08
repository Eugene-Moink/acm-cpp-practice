#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string ans = "";
    for (char c : s)
    {
        if (c == 'y' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            continue;

        else
        {
            ans += '.';
            ans += c;
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    while (s.size() % 3 != 0)
        s = "0" + s;

    for (int i = 0; i < s.size(); i += 3)
    {
        int num = (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
        cout << num;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
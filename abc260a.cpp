#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    map<char, int> cnt;
    for (char c : s)
    {
        cnt[c]++;
    }
    for (auto &p : cnt)
    {
        if (p.second == 1)
        {
            cout << p.first << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
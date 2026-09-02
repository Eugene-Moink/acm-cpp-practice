#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    map<string, int> mp;
    while (n--)
    {
        string s;
        cin >> s;
        if (mp.count(s) == 0)
        {
            mp[s] = 1;
            cout << "OK\n";
        }
        else if (mp.count(s) != 0)
        {
            cout << s << mp[s] << '\n';
            mp[s]++;
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
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;

    map<string, int> mp;
    int nxt_id = 1;

    while (q--)
    {
        string s;
        cin >> s;

        if (mp.count(s))
        {
            cout << mp[s] << '\n';
        }
        else
        {
            mp[s] = nxt_id;
            cout << nxt_id << '\n';
            nxt_id++;
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
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s, t;
    cin >> s >> t;

    for (int x = -10; x <= 10; ++x)
    {
        int cur = x;

        int dist_before = abs(cur);
        if (s[0] == 'L')
            cur--;
        else
            cur++;

        int dist_after = abs(cur);
        char expect1 = (dist_after < dist_before) ? 'C' : 'F';
        if (expect1 != t[0])
            continue;

        dist_before = abs(cur);
        if (s[1] == 'L')
            cur--;
        else
            cur++;

        dist_after = abs(cur);
        char expect2 = (dist_after < dist_before) ? 'C' : 'F';
        if (expect2 != t[1])
            continue;

        cout << x << '\n';
        return;
    }
    cout << "T_T" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
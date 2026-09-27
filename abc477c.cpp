#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll q;
    cin >> q;
    string S, T;
    cin >> S >> T;

    int n = S.size(), m = T.size();
    vector<int> pos;
    for (int i = 0; i + m <= n; i++)
    {
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if (S[i + j] != T[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            pos.push_back(i + 1);
    }

    while (q--)
    {
        ll L, R;
        cin >> L >> R;
        auto it = lower_bound(pos.begin(), pos.end(), L);
        if (it != pos.end() && *it <= R - m + 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
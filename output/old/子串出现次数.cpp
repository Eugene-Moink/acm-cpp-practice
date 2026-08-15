#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;

    vector<int> occ(n + 2, 0);
    for (int i = 1; i + m - 1 <= n; i++)
    {
        if (s.substr(i - 1, m) == t)
        {
            occ[i] = 1;
        }
    }

    vector<int> pref(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + occ[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (m > n)
        {
            cout << 0 << '\n';
            continue;
        }
        int L = l;
        int R = r - m + 1;
        if (L > R)
            cout << 0 << '\n';
        else
            cout << pref[R] - pref[L - 1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}
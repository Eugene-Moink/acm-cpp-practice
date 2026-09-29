#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1];
        if (i < n && s[i - 1] == 'A' && s[i] == 'C')
        {
            pref[i]++;
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r - 1] - pref[l - 1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
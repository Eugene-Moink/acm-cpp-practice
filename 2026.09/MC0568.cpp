#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (string &s : a)
        cin >> s;

    vector<int> cnt(n, 0);
    while (m--)
    {
        string x;
        cin >> x;
        for (int i = 0; i < n; i++)
        {
            if (a[i].rfind(x, 0) == 0)
                cnt[i]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << cnt[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
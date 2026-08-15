#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    int cnt_a = 0;
    int pos = 0;
    int x = 0;
    bool same = 0;

    for (int i = 0; i < n; ++i)
    {
        cnt_a += a[i];
        if (a[i] != b[i])
            same = 0;
        if (a[i] == 1 && b[i] == 0)
            x++;
    }

    if (same)
    {
        cout << 0 << '\n';
        return;
    }
    if (cnt_a == 0)
    {
        cout << -1 << '\n';
        return;
    }
    if (x == 0)
    {
        cout << -1 << '\n';
        return;
    }

    cout << (x % 2 ? 1 : 2) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
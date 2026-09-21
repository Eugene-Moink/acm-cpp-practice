#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int l = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            l = i;
            break;
        }
    }
    if (l == -1)
    {
        cout << "yes\n"
             << "1 1\n";

        return;
    }

    int r = l;
    while (r < n - 1 && a[r] > a[r + 1])
        r++;

    reverse(a.begin() + l, a.begin() + r + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            cout << "no\n";
            return;
        }
    }

    cout << "yes" << '\n'
         << l + 1 << ' ' << r + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
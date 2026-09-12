#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return;
    }

    int a;
    cin >> a;
    bool ok = 1;
    int tmp = a;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x != tmp)
        {
            ok = 0;
            break;
        }
    }
    if (ok)
        cout << 0;
    else
        cout << 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int cur = 0, cnt = 0, x;
    while (cin >> x)
    {
        for (int i = 0; i < x; i++)
        {
            cout << cur;
            if (++cnt == n)
            {
                cout << '\n';
                cnt = 0;
            }
        }
        cur = 1 - cur;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
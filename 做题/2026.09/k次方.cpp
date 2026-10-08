#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    ll cnt2 = 0, cnt3 = 0, cnt5 = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        while (x % 2 == 0)
        {
            cnt2++;
            x /= 2;
        }
        while (x % 3 == 0)
        {
            cnt3++;
            x /= 3;
        }
        while (x % 5 == 0)
        {
            cnt5++;
            x /= 5;
        }
    }
    cout << min({cnt2, cnt3, cnt5}) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
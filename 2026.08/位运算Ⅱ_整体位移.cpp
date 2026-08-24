#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll o, x, p;
    cin >> o >> x >> p;

    ll ans;
    if (o == 1)
    {
        ans = x << p;
    }
    else
    {
        ans = x >> p;
    }
    cout << ans << '\n';
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
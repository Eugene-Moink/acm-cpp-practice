#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char dig(int d)
{
    if (d < 10)
        return '0' + d;
    return 'A' + (d - 10);
}

void moink()
{
    ll x, m;
    cin >> x >> m;
    string ans = "";
    while (x != 0)
    {
        ans += dig(x % m);
        x /= m;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}
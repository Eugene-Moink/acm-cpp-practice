#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll m, a, b, c;
    cin >> m >> a >> b >> c;
    ll ans = 0;
    ll m1 = m;
    ll m2 = m;
    if (a <= m1)
    {
        m1 -= a;
        ans += a;
    }
    else
    {
        ans += m1;
        m1 = 0;
    }

    if (b <= m2)
    {
        m2 -= b;
        ans += b;
    }
    else
    {
        ans += m2;
        m2 = 0;
    }

    ans += min(c, m1 + m2);
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
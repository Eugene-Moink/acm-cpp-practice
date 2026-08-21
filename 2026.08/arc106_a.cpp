#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n;
    cin >> n;

    for (ll a = 1; a <= 40; ++a)
    {
        ll p3 = 1;
        for (int i = 0; i < a; i++)
        {
            p3 *= 3;
            if (p3 > n)
                break;
        }
        if (p3 > n)
            break;

        ll rem = n - p3;
        ll b = 0;
        ll p5 = 1;
        while (p5 < rem)
        {
            p5 *= 5;
            b++;
        }

        if (p5 == rem && b >= 1 && rem > 0)
        {
            cout << a << " " << b << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
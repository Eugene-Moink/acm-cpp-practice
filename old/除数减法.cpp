#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << '\n';
        return;
    }

    ll d = n;
    for (ll i = 3; i * i <= n; i+=2)
    {
        if(n % i == 0)
        {
            d = i;
            break;
        }
    }

    if(d == n)
        cout << 1 << '\n';
    else
        cout << 1 + (n - d) / 2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
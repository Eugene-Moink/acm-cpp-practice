#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

void moink()
{
    int a, b, k;
    cin >> a >> b >> k;
    ll cur = 1;
    for (int i = 1; i <= k; ++i)
    {
        if (i % a == 0)
            cur = cur * 2 % (2 * mod);
        if (i % b == 0)
        {
            if (cur % 2 == 0)
                cur /= 2;
            else
                cur = (cur + 1) / 2;
        }
    }
    cout << cur % mod << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
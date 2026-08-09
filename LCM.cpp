#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll b;
    cin >> b;
    ll ans = 0;
    for (ll i = 1; i * i <= b; ++i)
    {
        if(b % i== 0)
        {
            if(i * i == b)
                ans++;
            else
                ans += 2;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
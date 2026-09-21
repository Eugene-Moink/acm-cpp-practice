#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<long long, int> mp;
void init()
{
    for (int b = 1; b <= 100; b++)
    {
        ll num = 1LL * b * b * b * b;
        mp[num] = b;
    }
}

void moink()
{
    ll a;
    cin >> a;
    if (mp.count(a))
        cout << mp[a] << '\n';
    else
        cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
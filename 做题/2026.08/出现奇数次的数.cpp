#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        int x;
        cin >> x;
        ans = ans ^ x;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
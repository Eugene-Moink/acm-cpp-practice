#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int a, b;
    cin >> a >> b;
    int ans = __builtin_popcount(a ^ b);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
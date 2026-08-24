#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll a, b;
    cin >> a >> b;
    cout << (a | b) << ' ' << (a & b) << ' ' << (a ^ b) << '\n';
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
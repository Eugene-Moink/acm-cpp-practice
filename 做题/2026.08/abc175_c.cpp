#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll X, K, D;
    cin >> X >> K >> D;

    X = abs(X);

    ll cnt = min(K, X / D);

    X -= cnt * D;
    K -= cnt;

    if (K % 2 == 0)
    {
        cout << X << '\n';
    }
    else
    {
        cout << D - X << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= d && c <= b)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
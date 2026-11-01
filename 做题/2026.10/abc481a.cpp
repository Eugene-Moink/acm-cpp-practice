#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a + b >= 10)
        cout << 2;
    else
        cout << 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
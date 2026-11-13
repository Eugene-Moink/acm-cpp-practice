#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int a, b;
    cin >> a >> b;
    if ((a == 0 && b != 1) || (b == 0 && a != 1) || (a == 0 && b == 0))
    {
        cout << 1;
        return;
    }
    if ((a == 1 && b == 0) || (a == 0 && b == 1))
    {
        cout << 2;
        return;
    }
    cout << 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
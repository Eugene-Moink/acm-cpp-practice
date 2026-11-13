#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b || a == c || b == c)
        cout << "Yes";
    else
        cout << "No";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
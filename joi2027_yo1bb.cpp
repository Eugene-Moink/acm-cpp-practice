#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    if (n % 3 == 1)
        cout << "Ken";
    else if (n % 3 == 2)
        cout << "Ken";
    else
        cout << "Pa";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
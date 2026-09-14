#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    if (n <= 500000000LL / n)
    {
        cout << "O(n^2)\n";
    }
    else if (n <= 500000000LL)
    {
        cout << "O(n)\n";
    }
    else
    {
        cout << "O(1)\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
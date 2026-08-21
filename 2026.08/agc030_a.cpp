#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll A, B, C;
    cin >> A >> B >> C;

    if (C <= A + B + 1)
    {
        cout << B + C << '\n';
    }
    else
    {
        cout << B + (A + B + 1) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
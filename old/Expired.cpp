#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll x, a, b;
    cin >> x >> a >> b;
    if (b - a <= 0)
    {
        cout << "delicious" << endl;
    }
    else if (b - a > x)
    {
        cout << "dangerous" << endl;
    }
    else if (0 < b - a &&b - a <= x)
    {
        cout << "safe" << endl;
    }
}

int main()
{
    moink();
    return 0;
}
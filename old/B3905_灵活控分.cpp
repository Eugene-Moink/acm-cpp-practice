#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll a;
    cin >> a;

    int x = (a * a + 99) / 100;

    while (floor(10 * sqrt(x) + 1e-9) < a) 
    {
        x++;
    }
    cout << x << endl;
    return 0;
}
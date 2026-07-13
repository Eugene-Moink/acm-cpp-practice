#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll h;
    cin >> h;
    ll result = 0;
    ll day = 0;
    ll add = 1;

    while (result <= h)
    {
        result += add;
        add *= 2;
        day++;
    }

    cout << day << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int money;
    cin >> money;
    int total = x * 2 + y * 5 + z * 3;
    if(money>total)
    {
        cout << "Yes" << endl;
        cout << money - total << endl;
    }

    else
    {
        cout << "No" << endl;
        cout << total - money << endl;
    }

    return 0;
}
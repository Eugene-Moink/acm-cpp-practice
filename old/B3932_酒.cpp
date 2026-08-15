#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    double a, b, c, d, e, x, y;
    cin >> a >> b >> c >> d >> e >> x >> y;

    double drink1 = a * x + b * y;
    double drink2 = c * y;
    double drink3 = d * y + e;

    int id = 1;
    double max_drink = drink1;

    if (drink2 > max_drink) 
    {
        max_drink = drink2;
        id = 2;
    }
    if (drink3 > max_drink) 
    {
        max_drink = drink3;
        id = 3;
    }

    cout << id << " " << fixed << setprecision(2) 
    << max_drink << endl;
}

int main()
{
    moink();
    return 0;
}
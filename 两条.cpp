#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int k1, b1, k2, b2, c;
    cin >> k1 >> b1 >> k2 >> b2 >> c;
    double x1 = (double)(c - b1) / k1;
    double x2 = (double)(c - b2) / k2;
    double dist = fabs(x1 - x2);
    cout << fixed << setprecision(10) << dist;
}

int main()
{
    moink();
    return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double r = 5;
    const double PI = 3.14;

    double C, S, V;
    C = 2 * PI * r;
    S = PI * pow(r, 2);
    V = 4.0 / 3 * PI * pow(r, 3);

    cout << C << endl;
    cout << S << endl;
    cout << V << endl;

    return 0;
}
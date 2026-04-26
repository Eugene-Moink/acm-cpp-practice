#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double p = 0.5 * (a + b + c);
    double S = sqrt(p * (p - a) * (p - c) * (p - b));
    printf("%.1lf", S);

    return 0;
}
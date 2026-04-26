#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    int sum_1 = h1 * 60 + m1;
    int sum_2 = h2 * 60 + m2;
    int result = sum_2 - sum_1;

    cout << result << endl;
    return 0;
}
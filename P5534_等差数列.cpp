#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    long long a1, a2, n;
    cin >> a1 >> a2 >> n;

    long long d = a2 - a1;
    long long result = n * a1 + n * (n - 1) / 2 * d;

    cout << result << endl;
    return 0;
}
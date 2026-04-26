#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long result = 1;
    for (int i = 1; i <= n;i++)
    {
        int temp;
        cin >> temp;
        result *= temp;
    }

    if(result<1000000)
    {
        cout << result << endl;
    }
    else
    {
        cout << ">1000000" << endl;
    }

    return 0;
}
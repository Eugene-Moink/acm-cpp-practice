#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    ll result = 0;
    for (int i = 1; i <= n;i++)
    {
        result += i * (i + 1) / 2;
    }
    cout << result;
    return 0;
}
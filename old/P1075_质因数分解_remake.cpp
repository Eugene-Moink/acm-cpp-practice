#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    for (int i = 2; i * i <= n;i++)
    {
        if (n % i == 0)
        {
            cout << n / i << endl;
        }
    }
}

int main()
{
    moink();
    return 0;
}
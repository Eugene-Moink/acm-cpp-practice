#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin>>n;
    for (ll i = 2; i <= n / i;i++)
    {
        while (n % i == 0)
        {
            cout << i << endl;
            n /= i;
        }
    }

    if (n > 1)
    {
        cout << n << endl;
    }
}

int main()
{
    moink();
    return 0;
}
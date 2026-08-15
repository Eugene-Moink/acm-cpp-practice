#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool isPrime(ll n) 
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) 
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    ll number;
    cin >> number;

    bool prime = isPrime(number);
    bool even = 0;

    if(number%2==0)
    {
        even = 1;
    }

    if(prime)
    {
        cout << "P" << endl;
        return 0;
    }

    if(even)
    {
        cout << "E" << endl;
    }
    else{
        cout << "O" << endl;
    }
    return 0;
}
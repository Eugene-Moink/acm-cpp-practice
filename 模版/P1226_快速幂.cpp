#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long qpow(long long a,long long b,long long p)
{
    long long res = 1 % p;
    while(b)
    {
        if(b & 1)
        {
            res = (res * a) % p;
        }
        a=(a*a)%p;
        b >>= 1;
    }
    return res;
}
int main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    long long result = qpow(a, b, p);
    cout << a << "^" << b << " " << "mod " << p << "=" << result;
    return 0;
}
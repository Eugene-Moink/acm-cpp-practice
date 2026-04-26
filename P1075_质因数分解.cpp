#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long smaller_prime_factor = -1;

    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            smaller_prime_factor = i;
            break;
        }
    }

    long long larger_prime_factor = n / smaller_prime_factor;
    cout << larger_prime_factor << endl;

    return 0;
}
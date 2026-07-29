#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    if(n==1)
    {
        cout << 1 << endl;
        return;
    }
    vector<ll> prime;
    for (int i = 2; prime.size() < n - 1;i++)
    {
        bool isPrime = 1;
        for (int j = 2; j * j <= i;++j)
        {
            if(i%j==0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
        {
            prime.push_back(i);
        }
    }

    vector<ll> a(n);
    a[0] = prime[0];
    for (int i = 1; i < n - 1; i++)
    {
        a[i] = prime[i - 1] * prime[i];
    }
    a[n - 1] = prime[n - 2];
    for(ll x : a)
    {
        cout << x << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
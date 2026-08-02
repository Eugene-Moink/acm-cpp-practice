#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const int maxn = 10005;
bool is_prime[maxn];
vector<int> primes;

void init()
{
    fill(is_prime, is_prime + maxn, 1);
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i < maxn;i++)
    {
        if(is_prime[i])
        {
            for (int j = i * i; j < maxn;j+=i)
            {
                is_prime[j] = 0;
            }
        }
    }
}

void moink()
{
    int N;
    cin >> N;
    
    for (int x = 4; x <= N;x+=2)
    {
        for (int p = 2; p <= x / 2; p++)
        {
            if (is_prime[p] &&is_prime[x - p])
            {
                cout << x << "=" << p << "+" << x - p << endl;
                break;
            }
        }
    }
}

int main()
{
    init();
    moink();
    return 0;
}
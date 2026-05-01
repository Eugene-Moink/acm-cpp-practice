#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<bool> is_prime;
vector<int> prime;

void sieve(int n)
{
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    /*埃氏筛会超时（TLE）*/
    // for (int i = 2; i <= n;i++)
    // {
    //     if(is_prime[i]==true)
    //     {
    //         if((long long)i * i <= n) {
    //             for (long long j = (long long)i * i; j <= n; j += i) 
    //             {
    //                 is_prime[j] = false;
    //             }
    //         }
    //     }
    // }

    /*改为欧式筛*/
    for (int i = 2; i <= n;i++)
    {
        if(is_prime[i])
        {
            prime.push_back(i);
        }

        for (int j = 0; j < prime.size() && i * prime[j] <= n;j++)
        {
            is_prime[i * prime[j]] = false;
            if(i%prime[j]==0)
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    sieve(n);
    
    while(q--) 
    {
        int k;
        cin >> k;
        cout << prime[k - 1] << endl;
    }
    
    return 0;
}
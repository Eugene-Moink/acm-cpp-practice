#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;

    vector<bool> is_prime(m + 1,true);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= sqrt(m);i++){
        if(is_prime[i]==1){
            for (int j = i * i; j <= m;j+=i)
            {
                is_prime[j] = 0;
            }
        }
    }

    vector<long long> prefix(m + 1);
    prefix[0] = 0;
    for (int k = 1; k <= m;k++){
        prefix[k] = prefix[k - 1] + (is_prime[k] ? 1 : 0);
    }

        while (n--)
        {
            long long l, r;
            cin >> l >> r;
            if (r > m || r < 1 || l < 1 || l > r || l > m)
            {
                cout << "Crossing the line" << endl;
            }
            else{
                long long result = prefix[r] - prefix[l - 1];
                cout << result << endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool isPrime(int n) 
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void moink()
{
    int l, r;
    cin >> l >> r;
    if (l <= 2 && 2 <= r) cout << 2 << endl;
    if (l <= 3 && 3 <= r) cout << 3 << endl;
    if (l <= 5 && 5 <= r) cout << 5 << endl;
    if (l <= 7 && 7 <= r) cout << 7 << endl;
    if (l <= 11 && 11 <= r) cout << 11 << endl;

     for (int len = 3; len <= 7; len += 2) 
    {
        int half_len = (len + 1) / 2;          
        int start = pow(10, half_len - 1);     
        int end = pow(10, half_len) - 1;       

        for (int half = start; half <= end; half++)
        {
            
            if ((half / (int)pow(10, half_len - 1)) % 2 == 0) continue;

            
            string s = to_string(half);
            string rev = s;
            reverse(rev.begin(), rev.end());

            long long pal;
            if (len % 2 == 0) 
                pal = stoll(s + rev);
            else
                pal = stoll(s + rev.substr(1)); 

            if (pal >= l && pal <= r && isPrime((int)pal))
            {
                cout << pal << endl;
            }
        }
    }
}


int main()
{
    moink();
    return 0;
}

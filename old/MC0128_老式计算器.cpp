#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    //特判"1"!!!!!!!!
    if (k == 1) {
        cout << n << endl;  
        return 0;
    }

    int cnt = 0;
    while (n!=0)
    {
        
        if (n % k != 0) 
        {
            cnt += n % k;  
            n -= n % k;    
        }
        
        else 
        {
            n /= k;
            cnt++;
        }
    }
    cnt += n;

    cout << cnt << endl;
    return 0;
}
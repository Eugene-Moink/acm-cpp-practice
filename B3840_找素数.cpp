#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0;
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b;i++)
    {
        bool isPrime = true;
        if(i<2)
        {
            isPrime = false;
        }

        for (int j = 2; j <= sqrt(i);j++)
        {
            if(i%j==0)
            {
                isPrime = false;
                break;
            }
        }

            if (isPrime) 
            {
                cnt++;
            }

    
    }

    cout << cnt << endl;
    return 0;
}
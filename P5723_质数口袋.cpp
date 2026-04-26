#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;

    int cnt = 0;
    for (int i = 2;i<=n;i++)
    {

        int sign = 0;
        if (i==1)
        {
            continue;
        }
        
        for (int k = 2; k <= sqrt(i);k++)
        {

            if (i % k != 0)
            {
                continue;
            }
            else
            {
                sign = 1;
                break;
            }


            
        }


        if(sign==0)
        {
            if(sum+i>n)
            {
                break;
            }
            sum += i;
            cout << i << endl;
            cnt++;
        }


        if (sign==1)
        {
            continue;
        }

        
        
    }

    cout << cnt << endl;

    return 0;
}
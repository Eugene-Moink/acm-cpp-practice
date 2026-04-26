#include<iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0;i<n;i++)
    {

        long long number;
        cin >> number;
        int o = 0;
        if (number==1)
        {
            cout << "No" << endl;
            continue;
        }
        
        for (int k = 2; k <= sqrt(number);k++)
        {
            if (number % k != 0)
            {
                continue;
            }
            else
            {
                o = 1;
                break;
            }
            
        }

        if(o==0)
        {
            cout << "Yes" << endl;
        }

        if (o==1)
        {
            cout << "No" << endl;
        }
        
    }

    return 0;
}
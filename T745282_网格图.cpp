#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 2*n+1; i++)
    {
        for (int j = 1; j <= 2*m+1; j++)
        {
            if(i%2!=0)
            {
                if(j%2!=0)
                {    
                    cout << "+";
                }
                else
                {
                    cout << "-";
                }
                
            }

            else
            {
               if(j%2!=0)
                {    
                    cout << "|";
                }
                else
                {
                    cout << " ";
                } 
            }

           
        }

         cout << endl;
    }

    return 0;
}
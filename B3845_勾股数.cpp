#include<bits/stdc++.h>
using namespace std;

 int main()
 {
    int n;
    cin >> n;

    int count = 0;
    for (int a = 1; a <= n;a++)
    {
        for(int b = a; b <= n;b++)
        {
            long long sum = a*a + b*b;
            long long c = sqrt(sum);

            if (c * c == sum && c <= n) 
            {
            count++;
            }

            if (a*a + b*b > n*n) 
            break;    
        }
    }

    cout << count << endl;
    return 0;
 }
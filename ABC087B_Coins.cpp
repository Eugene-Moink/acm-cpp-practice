#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int count = 0;

    for (int i = 0; i <= a;i++)
    {
        for (int j = 0; j <= b;j++)
        {
            int remaining = x - 500 * i - 100 * j;
            
            if(remaining >= 0 && remaining % 50 == 0)
            {
                    int need_c = remaining / 50;

                    if(need_c<=c)
                    {
                        count++;
                    }
            }
        }
    }

    cout << count << endl;
    return 0;
}
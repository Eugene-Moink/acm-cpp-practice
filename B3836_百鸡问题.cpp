#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int x, y, z, m, n;
    int cnt = 0;
    cin >> x >> y >> z >> m >> n;

    int max_a = (x > 0) ? min(m, n / x) : m;
    for (int a = 0; a <= max_a;a++)
    {
        int max_b = (y > 0) ? min(m - a, (n - a * x) / y) : m - a;
        for (int b = 0; b <= max_b;b++)
        {
            int rest_chi = m - a - b;
            int rest_money = n - a * x - b * y;

            if(rest_chi>=0 && rest_chi%z==0 && rest_money >= 0 && (rest_chi/z==rest_money))
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}
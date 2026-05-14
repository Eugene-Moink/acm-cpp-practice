#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int wins = 0;
        
        // 情况1: Sunee(a1,a2) vs Slavic(b1,b2)
        int s1 = (a1 > b1) + (a2 > b2);
        int sl1 = (b1 > a1) + (b2 > a2);
        if (s1 > sl1) wins++;
        
        // 情况2: Sunee(a1,a2) vs Slavic(b2,b1)
        int s2 = (a1 > b2) + (a2 > b1);
        int sl2 = (b2 > a1) + (b1 > a2);
        if (s2 > sl2) wins++;
        
        // 情况3: Sunee(a2,a1) vs Slavic(b1,b2)
        int s3 = (a2 > b1) + (a1 > b2);
        int sl3 = (b1 > a2) + (b2 > a1);
        if (s3 > sl3) wins++;
        
        // 情况4: Sunee(a2,a1) vs Slavic(b2,b1)
        int s4 = (a2 > b2) + (a1 > b1);
        int sl4 = (b2 > a2) + (b1 > a1);
        if (s4 > sl4) wins++;
        
        cout << wins << endl;
    }

    return 0;
}
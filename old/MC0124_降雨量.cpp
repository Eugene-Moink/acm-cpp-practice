#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int A, B, H1, H2, H, n;
    cin >> A >> B >> H1 >> H2 >> H >> n;

    bool open = 0;
    int result = H;

    while(n--)
    {
        result -= A;

        int rain;
        cin >> rain;
        result += rain;

        if(open) 
        {
            result -= B;
        }
        
        if(result >= H1) open = 1;     
        else if(result <= H2) open = 0;     
        
        result = max(result, 0);
    }
    
    cout << result << endl;
    return 0;
}
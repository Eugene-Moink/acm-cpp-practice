#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int T, S, t;
    cin >> T >> S >> t;
    if(T >= 35) 
{
    if(S == 1 && t >= 33) 
    {  // 需要同时满足S=1和t>=33
        cout << "Bu Tie" << endl;
        cout << T << endl;
    } 
    else if(S == 0) 
    {
        cout << "Shi Nei" << endl;
        cout << T << endl;
    }
    else 
    { // S == 1 && t < 33
        cout << "Bu Re" << endl;
        cout << t << endl;
    }
} 
    else 
    { // T < 35
        if(t < 33) 
        {
            cout << "Shu Shi" << endl;
            cout << t << endl;
        } 
        else 
        { // t >= 33
            cout << "Bu Re" << endl;
            cout << t << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a+b>=10||a+c>=10||c+b>=10)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
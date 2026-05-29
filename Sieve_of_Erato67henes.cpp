#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool find = 0;
        for (int i = 1; i <= n;i++)
        {
            int number;
            cin >> number;
            if(number==67)
            {
                find = 1;
            }
        }
        if(find)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
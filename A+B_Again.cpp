#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string number;
        cin >> number;
        int result = 0;
        for (int i = 0; i < number.size();i++)
        {
            result += number[i] - '0';
        }
        cout << result << endl;
    }
    return 0;
}
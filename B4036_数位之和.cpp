#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        int number;
        cin >> number;
        string num = to_string(number);
        int temp = 0;
        for (int j = 0; j < num.size();j++)
        {
            temp += num[j] - '0';
        }
        if(temp%7==0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    string str;
    cin >> str;
    int number;
    cin >> number;

    for (int i = number; i < str.size() - number; i++)
    {
        cout << str[i];
    }
    return 0;
}
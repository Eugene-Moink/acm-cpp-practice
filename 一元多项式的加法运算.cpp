#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    map<int, int, greater<int>> poly1, poly2;
    int n1;
    cin >> n1;
    for (int i = 0; i < n1;i++)
    {
        int coeff, exp;
        cin >> coeff >> exp;
        poly1[exp] = coeff;
    }

    int n2;
    cin >> n2;
    for (int i = 0; i < n2;i++)
    {
        int coeff, exp;
        cin >> coeff >> exp;
        poly2[exp] = coeff;
    }

    map<int, int, greater<int>> result;
    for(auto& item:poly1)
    {
        result[item.first] = item.second;
    }

    for(auto& item:poly2)
    {
        int exp = item.first;
        int coeff = item.second;

        result[exp] += coeff;
    }

    bool output = 0;
    for(auto& item : result)
    {
        if(item.second != 0) 
        {  
            cout << item.second << " " << item.first << endl;
            output = 1;
        }
    }

    if(!output)
    {
        cout << "0 0" << endl;
    }
    return 0;
}
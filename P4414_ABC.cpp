#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> number;
    for (int i = 0; i < 3;i++)
    {
        int num;
        cin >> num;
        number.push_back(num);
    }
    sort(number.begin(), number.end());
    for(int i = 0; i < 3;i++)
    {
        char abc;
        cin >> abc;
        if(abc=='A')
        {
            cout << number[0];
        }

        if(abc=='B')
        {
            cout << number[1];
        }

        if(abc=='C')
        {
            cout << number[2];
        }

        if(i<2)
        {
            cout << " ";
        }
    }

    return 0;
}
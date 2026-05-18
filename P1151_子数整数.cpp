#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int k;
    bool found = 0;
    cin >> k;

    for (int l = 10000; l <= 30000;l++)
    {
        string number= to_string(l);

        string num1=number.substr(0, 3);
        string num2=number.substr(1, 3);
        string num3=number.substr(2, 3);

        int num_1 = stoi(num1);
        int num_2 = stoi(num2);
        int num_3 = stoi(num3);
        
        if(num_1%k==0 && num_2%k==0 && num_3%k==0)
        {
            cout << number << endl;
            found = 1;
        }
    }
    if (!found) 
        {
            cout << "No" << endl;
        }

    return 0;
}
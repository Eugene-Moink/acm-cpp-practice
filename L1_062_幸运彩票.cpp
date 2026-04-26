#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        string number;
        cin >> number;
        int temp_1 = (number[0] - '0') + (number[1] - '0') + (number[2] - '0');
        int temp_2 = (number[3] - '0') + (number[4] - '0') + (number[5] - '0');

        if(temp_1==temp_2)
        {
            cout << "You are lucky!" << endl;
        }

        else
        {
            cout << "Wish you good luck." << endl;
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int sum = 0;
        string num;
        cin >> num;
        for (int j = 0; j < num.length();j++)
        {
            int temp_1 = num[j] - '0';
            sum += (int)(pow(temp_1, num.length()) + 0.5);
        }

        int temp_2 = stoi(num);
        if(sum==temp_2)
        {
            cout << "T"<<endl;
        }
        else
            cout << "F" << endl;
    }

    return 0;
}

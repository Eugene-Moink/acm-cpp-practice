#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    vector<int> number;
    for (int i = 0; i < 7;i++)
    {
        int temp;
        cin >> temp;
        number.push_back(temp);
    }

    int max_num = number[0];
    int sum_temp = 0;

    for (int j = 0; j < 7;j++)
    {
        sum_temp += number[j];
        max_num = max(max_num, number[j]);
    }

    int result = max_num * 2 - sum_temp;

    cout << result << endl;
    return 0;
}
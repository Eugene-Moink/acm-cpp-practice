#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long total = 0;
    vector<string> name;
    vector<int> number;
    for (int i = 0; i < n;i++)
    {
        string name_temp;
        int number_temp;
        cin >> name_temp >> number_temp;
        name.push_back(name_temp);
        number.push_back(number_temp);
        total += number_temp;
    }

    int target = total / number.size() / 2;
    vector<int> to_reach;
    for (int j = 0; j < n;j++)
    {
        int temp = abs(target - number[j]);
        to_reach.push_back(temp);
    }

    int min_reach = to_reach[0];
    int winner_idx = 0;
    for (int k = 0; k < n;k++)
    {
        if(to_reach[k]<min_reach)
        {
            min_reach = to_reach[k];
            winner_idx = k;
        }
    }

    cout << target << " " << name[winner_idx] << endl;
    return 0;
}
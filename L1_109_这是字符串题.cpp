#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    string abc;
    cin >> abc;
    int abc_cnt[26] = {0};
    vector<int> abc_goal;
    for (int i = 0; i < 26;i++)
    {
        int goal;
        cin >> goal;
        abc_goal.push_back(goal);
    }
    for (int j = 0; j < abc.size();j++)
    {
        abc_cnt[abc[j] - 'a']++;
    }

    long long result = 0;

    for (int k = 0; k < 26;k++)
    {
        cout << abc_cnt[k];
        if(k<25)
        {
            cout << " ";
        }
        result += abc_cnt[k] * abc_goal[k];
    }
    cout << endl
         << result << endl;
    return 0;
}
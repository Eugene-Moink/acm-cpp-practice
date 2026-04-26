#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> number;
    for (int i = 1; i <= n;i++)
    {
        int num;
        cin >> num;
        number.push_back(num);
    }
    for (int j = 0;j<n;j++)
    {
        int target = number[j];
        bool found = false;
        for (int k = 1; k * k < target; k++)
        {
            int remain = target - k * k;
            int y = sqrt(remain);
            if(y*y==remain&&y>0)
            {
                found = true;
                break;
            }
        }
        if(found)
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
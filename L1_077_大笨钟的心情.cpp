#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    vector<int> mood;
    for (int i = 0; i < 24;i++)
    {
        int number;
        cin >> number;
        mood.push_back(number);
    }
    while(1)
    {
        int time;
        cin >> time;
        if(time>=0&&time<=23)
        {
            cout << mood[time] <<" ";
            if(mood[time]>50)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }

        else
        {
            break;
        }
    }
    return 0;
}
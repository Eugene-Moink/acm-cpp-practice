#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int number;
        cin >> number;
        vector<int> temp;
        for (int i = 1; i <= number;i++)
        {
            string tap;
            cin >> tap;
            for (int i = 0; i < tap.size();i++)
            {
                if(tap[i]=='#')
                {
                    int temp_tap = i + 1;
                    temp.push_back(temp_tap);
                }
            }
        }

        reverse(temp.begin(), temp.end());
        for (int i = 0; i < temp.size();i++)
        {
            cout << temp[i];
            if(i<temp.size()-1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
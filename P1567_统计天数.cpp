#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> temp;
    int n;
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        int tempture;
        cin >> tempture;
        temp.push_back(tempture);
    }

    int max_length = 1;
    int current_length = 1;
    for (int day = 1; day < n;day++)
    {
        if (temp[day]>temp[day-1])
        {
            current_length++;
        }
        else
        {
            current_length = 1;
        }

        max_length = max(max_length, current_length);
    }

    cout << max_length << endl;

    return 0;
} 
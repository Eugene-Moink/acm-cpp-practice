#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n;i++)
    {
        int number;
        cin >> number;
        num.push_back(number);
    }

    sort(num.begin(), num.end());

    for (int m = 0; m < n;m++)
    {
        cout << num[m];
        if (m<n-1)
        {
            cout << " ";
        }
        
    }

    cout << endl;

    return 0;
}
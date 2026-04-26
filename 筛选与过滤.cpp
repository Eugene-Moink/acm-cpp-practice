#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> num(n);
    vector<int> even;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        num[i] = number;
    }

    for (int m = 0; m < n; m++)
    {
        if (num[m]%2==0)
        {
            even.push_back(num[m]);
        }
        
    }

    for (int j = 0; j < even.size();j++)
    {
        cout << even[j];
        if (j!=even.size()-1)
        {
            cout << " ";
        }
        
    }

    cout << endl;

    return 0;
}
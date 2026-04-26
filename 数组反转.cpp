#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n;i++)
    {
        int number;
        cin >> number;
        num[i] = number;
    }

    reverse(num.begin(), num.end());

    for (int i = 0; i < n; i++)
    {
        cout << num[i];
        if (i!=n-1)
        {
            cout << " ";
        }
        
    }

    cout << endl;

    return 0;
}
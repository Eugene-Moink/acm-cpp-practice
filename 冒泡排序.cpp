#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> number;
    for (int i = 0; i < n;i++)
    {
        int num;
        cin >> num;
        number.push_back(num);
    }

    sort(number.begin(), number.end());

    for (int i = 0; i < n;i++)
    {
        cout << number[i];
        if(i<n-1)
        {
            cout << " ";
        }
    }

    cout << endl;
    return 0;
}
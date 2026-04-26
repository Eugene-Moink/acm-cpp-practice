#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> num(n);
    for (int i = 0; i < n;i++)
    {
        int number;
        cin >> number;
        num[i] = number;
    }

    auto it = find(num.begin(), num.end(), x);

    if (it==num.end())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << it - num.begin() << endl;
    }
    

    cout << endl;

    return 0;
}
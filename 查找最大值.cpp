#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int max_num = -1e9 - 1;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        num[i] = number;
        max_num=max(max_num, num[i]);
    }

    cout << max_num << endl;

    return 0;
}
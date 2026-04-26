#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int max_temp = -1;
    for (int i = 0; i < n;i++)
    {
        int number;
        cin >> number;
        if(number>max_temp)
        {
            max_temp = max(number, max_temp);
        }

        if(i==n-1&&max_temp!=k)
        {
            max_temp = number;
        }
    }

    cout << max_temp << endl;
    return 0;
}
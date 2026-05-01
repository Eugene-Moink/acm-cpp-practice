#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> number(n);
    for (int i = 0; i < n;i++)
    {
        cin >> number[i];
    }

    long long max_num = 0;
    long long current_sum = 0;

    for (int i = 0; i < n;i++)
    {
        
        current_sum += number[i];
        if(current_sum>max_num)
        {
            max_num = current_sum;
        }
        if(current_sum<0)
        {
            current_sum = 0;
        }
    }

    cout << max_num << endl;
    return 0;
}
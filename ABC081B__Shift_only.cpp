#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    int n;
    cin >> n;

    vector<long long> number;
    for (int i = 0; i < n;i++)
    {
        long long temp;
        cin >> temp;
        number.push_back(temp);
    }

    vector<int> cnt_num(n);

    for (int j = 0; j < n;j++)
    {
        int cnt = 0;
        while(number[j]%2==0)
        {
            number[j] = number[j] / 2;
            cnt++;
        }
         cnt_num[j] = cnt;
    }

    int min_cnt = cnt_num[0];
    for (int k = 0; k < n;k++)
    {
        min_cnt = min(min_cnt, cnt_num[k]);
    }

    cout << min_cnt << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string number;
    cin >> number;
    int cnt[10] = {0};

    for (int i = 0; i < number.size();i++)
    {
        int now_number = number[i] - '0';
        cnt[now_number]++;
    }

    for (int j = 0; j <= 9;j++)
    {
        if(cnt[j]!=0)
        {
            cout << j << ":" << cnt[j] << endl;
        }
    }

    return 0;
}
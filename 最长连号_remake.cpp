#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int first_number;
    cin >> first_number;

    int before_number = first_number;
    int cnt = 1;
    int max_cnt = 1;

    if(n==1)
    {
        cout << cnt << endl;
        return 0;
    }

    if(n==0)
    {
        cnt = 0;
        cout << cnt << endl;
        return 0;
    }

    for (int i = 2; i <= n;i++)
    {
        int number;
        cin >> number;
        if(number==before_number+1)
        {
            cnt++;
        }

        else
        {
            max_cnt = max(cnt, max_cnt);
            cnt = 1;
        }

        before_number = number;
    }

    max_cnt = max(cnt, max_cnt);

    cout << max_cnt << endl;
    return 0;
}
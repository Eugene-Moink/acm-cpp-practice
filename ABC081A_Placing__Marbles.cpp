#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
    string s3;
    cin >> s3;
    int cnt = 0;
    for (int i = 0; i < 3;i++)
    {
        if(s3[i]=='1')
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    string str;
    cin >> str;
    long long cnt = 0;
    for (long long i = 0; i < str.size();i++)
    {
        if(str[i]=='C')
        {
            cnt += min(i + 1, (long long)str.size() - i);
        }
    }
    cout << cnt << endl;
    return 0;
}
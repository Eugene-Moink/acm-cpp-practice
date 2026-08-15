#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    int n = s.size();

    int pos0 = -1;
    for (int i = 0; i < n;i++)
    {
        if(s[i]=='0')
        {
            pos0 = i;
            break;
        }
    }

    string temp;
    for (int i = 0; i < n;++i)
    {
        if(i!=pos0)
        {
            temp.push_back(s[i]);
        }
    }

    int pos1_in_temp = -1;
    for (int i = 0; i < (int)temp.size();++i)
    {
        if(temp[i]=='1')
        {
            pos1_in_temp = i;
            break;
        }
    }

    int pos1 = -1;
    int cnt = 0;
    for (int i = 0; i < n;++i)
    {
        if(i==pos0)
        continue;
        if(cnt==pos1_in_temp)
        {
            pos1 = i;
            break;
        }
        ++cnt;
    }

    for (int i = 0; i < n;i++)
    {
        if (i == pos1 || i == pos0)
        continue;
        cout << s[i];
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
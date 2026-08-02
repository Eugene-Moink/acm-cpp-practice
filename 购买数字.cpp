#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;

    while (s.size() > 1 && s[0] == '0') 
    {
        s.erase(s.begin());
    }

    string c = s;
    int len = s.size();
    for (int i = 0; i < len / 2;i++)
    {
        c[len - 1 - i] = c[i];
    }

    if (c > s)
    {
        int mid = (len - 1) / 2;
        while (mid >= 0 && c[mid] == '0')
        {
            c[mid] = '9';
            mid--;
        }
        c[mid]--;
        for (int i = mid + 1; i < len;i++)
        {
            c[i] = '9';
        }

        for (int i = 0; i < len / 2;i++)
        {
            c[len - 1 - i] = c[i];
        }
    }

    if(c[0]=='0')
    {
        cout << string(len - 1, '9') << endl;
    }
    else
    {
        cout << c << endl;
    }
}

int main()
{
    moink();
    return 0;
}
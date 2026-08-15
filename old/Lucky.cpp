#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size();i++)
    {
        if(i<3)
        {
            a += s[i] - '0';
        }
        else
        {
            b += s[i] - '0';
        }
    }

    if(a==b)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    int i = 0;
    while(i<n)
    {
        if (s[i] == 'W')
        {
            i++;
            continue;
        }
        int cntR = 0, cntB = 0;
        while (i < n && s[i] != 'W') 
        {
            if (s[i] == 'R') cntR++;
            else cntB++;
            i++;
        }
        
        if (cntR == 0 || cntB == 0) 
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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
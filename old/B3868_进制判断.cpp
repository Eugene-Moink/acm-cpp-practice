#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;

        int mv = -1;
        for (int i = 0; i < s.size();i++)
        {
            int v = 0;
            if (s[i] >= '0' && s[i] <= '9') v = s[i] - '0';
            else if (s[i] >= 'A' && s[i] <= 'Z') v = s[i] - 'A' + 10;
            mv = max(mv, v);
        }

        cout << (mv <= 1) << ' ' << (mv <= 7) << ' ' << (mv <= 9) << ' ' << (mv <= 15) << "\n";
    }
    return 0;
}
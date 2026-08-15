#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        ll ans = 0;
        for (int i = 0; i < s.size();)
        {
            if(s[i]=='B')   
            {
                i += k;
                ans++;
            }        
            
            else
            {
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
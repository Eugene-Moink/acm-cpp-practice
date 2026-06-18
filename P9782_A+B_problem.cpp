#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    char a, b;
    cin >> a >> b;
    ll num = (a - 'A') + (b - 'A');
    string ans = "";

    if (num < 26)
    {
        ans += (char)'A' + num;
    }

    else
    {
        string s = "";
        while(num > 0)
        {
            ll temp = num % 26;
            if(temp == 0)
            {
                s += 'Z';
                num = num / 26 - 1;
            }
            else
            {
                s += 'A' + temp - 1; 
                num /= 26;
            }
        }
        reverse(s.begin(), s.end());
        ans = s;
    }

    cout << ans << endl;
    return 0;
}
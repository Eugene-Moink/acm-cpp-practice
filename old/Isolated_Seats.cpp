#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        if(s[i]=='x')
        {
            bool left = (i == 0 || s[i - 1] == 'x');
            bool right = (i == n - 1 || s[i + 1] == 'x');
            if (left &&right)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
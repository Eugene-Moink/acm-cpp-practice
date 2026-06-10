#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
{
    int n;
    string s;
    cin >> n >> s;

    int l = 0, r = n - 1;

    while (l < r && s[l] != s[r])
    {
        l++;
        r--;
    }

    int ans = r - l + 1;
    if (ans < 0) ans = 0;

    cout << ans << endl;
}
}
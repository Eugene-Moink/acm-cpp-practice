#include<bits/stdc++.h>
using ll = long long;
using namespace std;
void moink()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    int i = 0;
    while (i < s.size())
    {
        char c = s[i];
        ans.push_back(c);
        i++;
        while (i < s.size() && s[i] != c)
        {
            i++;
        }
        i++;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
}
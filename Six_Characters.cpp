#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    string ans = "";
    while((int)ans.size() < 6) 
    {
        ans += s;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}
#include<bits/stdc++.h>
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i + 1 < s.size();i++)
    {
        if(s[i] != s[i+1])
            cnt++;
    }
    cout << (cnt == 1 ? 2 : 1) << '\n';
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
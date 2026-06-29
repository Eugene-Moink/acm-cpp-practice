#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < s.size();i++)
    {
        
        int idx = s[i] - 'a';
        int new_idx = (idx + n) % 26;
        char new_char = 'a' + new_idx;
        cout << new_char;
    }
    return 0;
}
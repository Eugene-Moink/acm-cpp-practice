#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

string s;

void solve()
{
    cin >> s;
    if (s.size() % 2 == 1)
    {
        cout << "No" << endl;
        return;
    }

    for (ll i = 0; i < s.size();i+=2)
    {
        if(!(s[i]==s[i+1]))
        {
            cout << "No" << endl;
            return;
        }
    }

    int cnt[26] = {0}; 
    for (int i = 0; i < s.size(); i++) 
    {
        cnt[s[i] - 'a']++; 
    }

    for (int i = 0; i < 26; i++) 
    {
  
        if (cnt[i] != 0 && cnt[i] != 2) 
        {
            cout << "No" << endl;
            return; 
        }
    }

    cout << "Yes" << endl;

}

int main()
{
    solve();
    return 0;
}
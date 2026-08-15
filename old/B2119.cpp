#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main() 
{
    string s;
    cin >> s;

    
    if (s.size() >= 3 && s.substr(s.size()-3, 3) == "ing") 
    {
        s = s.substr(0, s.size()-3);
    }
    
    else if (s.size() >= 2 && s.substr(s.size()-2, 2) == "er") 
    {
        s = s.substr(0, s.size()-2);
    }
    
    else if (s.size() >= 2 && s.substr(s.size()-2, 2) == "ly") 
    {
        s = s.substr(0, s.size()-2);
    }
    cout << s << endl;
    return 0;
}
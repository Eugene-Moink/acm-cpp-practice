#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    unordered_set<string> unique_roots; 

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        bool appeared[26] = {false};
        for (int j = 0; j < s.size(); j++) 
        {
            appeared[s[j] - 'a'] = true;
        }

        string root = "";
        for (int j = 0; j < 26; j++) 
        {
            if (appeared[j])
            {
                root += (char)('a' + j);
            }
        }

        unique_roots.insert(root); 
    }

    cout << unique_roots.size() << endl;
}

int main()
{
    moink();
    return 0;
}
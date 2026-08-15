#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;
    vector<string> result;
    int i = n - 1;
    while (i>=0)
    {
        if(s[i]=='a'||s[i]=='e')
        {
            result.push_back(s.substr(i - 1, 2));
            i -= 2;
        }
        else
        {
            result.push_back(s.substr(i - 2, 3));
            i -= 3;
        }
    }
    
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size();i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << ".";
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
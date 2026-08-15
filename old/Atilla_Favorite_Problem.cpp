#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;
    int need = 0;
    for (int i = 0; i < n;i++)
    {
        need = max(need, s[i] - 'a' + 1);
    }
    cout << need << endl;
    
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
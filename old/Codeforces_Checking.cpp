#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;

    for (int i = 1; i <= n;i++)
    {
        char c;
        cin >> c;
        string str = "codeforces";
        if (str.find(c) != string::npos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
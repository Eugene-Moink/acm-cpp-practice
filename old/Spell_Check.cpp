#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    string s;
    cin >> n >> s;   

    if (n != 5)
    {
        cout << "NO" << endl;
        return;      
    }

    sort(s.begin(), s.end());
    string name = "Timur";
    sort(name.begin(), name.end());

    if (s == name)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n,m;
    cin >> n;
    string s,b,c;
    cin >> s;
    cin >> m;
    cin >> b >> c;

    string front = "", back = "";
    for (ll i = 0; i < m;i++)
    {
        if(c[i]=='D')
        {
            back += b[i];
        }
        else
        {
            front += b[i];
        }
    }
    reverse(front.begin(), front.end());

    cout << front + s + back << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
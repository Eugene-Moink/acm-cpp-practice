#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    string a, b;     
    cin >> a >> b;

    for (ll i = 0; i < n;i++)
    {
        if (a[i] != b[i])
        {
            if (!((a[i] == 'G' && b[i] == 'B') || (a[i] == 'B' && b[i] == 'G')))
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
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
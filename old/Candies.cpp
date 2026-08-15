#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> ops;
    if(n%2==0)
    {
        cout << "-1" << endl;
        return;
    }

    while(n!=1)
    {
        if (n % 4 == 1)
        {
            ops.push_back(1);
            n = (n + 1) / 2;
        }

        else if (n % 4 == 3)
        {
            ops.push_back(2);
            n = (n - 1) / 2;
        }
    }
    reverse(ops.begin(), ops.end());
    cout << ops.size() << endl;
    for (ll i = 0; i < ops.size();i++)
    {
        cout << ops[i];
        if(i<ops.size()-1)
        {
            cout << " ";
        }
    }
    cout << endl;
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
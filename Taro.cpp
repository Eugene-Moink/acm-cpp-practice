#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> child(n + 1, 0);
    while(m--)
    {
        ll family;
        char baby;
        cin >> family >> baby;
        if(baby=='F')
        {
            cout << "No" << endl;
            continue;
        }
        
        child[family]++;

        if(child[family]==1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
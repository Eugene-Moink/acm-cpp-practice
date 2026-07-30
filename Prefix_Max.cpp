#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    ll maxn = -1;
    for (int i = 0; i < n;i++)
    {
        ll x;
        cin >> x;
        maxn = max(maxn, x);
    }
    cout << maxn * n << endl;
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
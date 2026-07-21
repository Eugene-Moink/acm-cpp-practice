#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll q, w, e, r;
    cin >> q >> w >> e >> r;
    ll cnt = 0;
    if(q<w)
        cnt++;
    if(q<e)
        cnt++;
    if(q<r)
        cnt++;

    cout << cnt << endl;
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
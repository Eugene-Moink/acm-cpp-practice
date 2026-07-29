#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int h, w;
    cin >> h >> w;
    int r, c;
    cin >> r >> c;
    int ans = 4;

    if(r==1)
        ans--;

    if(r==h)
        ans--;

    if(c==1)
        ans--;

    if(c==w)
        ans--;

    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main() 
{
    ll type, a, b, c, d;
    cin >> type >> a >> b >> c >> d;
    if(type==0)
    {
        cout << a + b<<endl;
    }

    else
    {
        cout << max(a - c, (ll)0) + max(b - d, (ll)0) << endl;
    }
    return 0;
}

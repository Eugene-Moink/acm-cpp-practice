#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n, k, c;
    cin >> n >> k >> c;
    ll cnt = n % k;
    ll result = 0;
    if(cnt==0)
    {
        result = k * c;
    }
    if(cnt>0)
    {
        result = c * cnt;
    }
    cout << result << endl;
    return 0;
}
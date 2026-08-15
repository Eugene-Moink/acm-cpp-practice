#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;

    ll left = 1, right = 1e6;
    ll ans = 0;
    while(left<=right)
    {
        ll mid = left + (right - left) / 2;

        if(mid*mid*mid<=n)
        {
            ans = mid;
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
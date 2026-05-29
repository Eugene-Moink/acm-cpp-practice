#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, s, x;
        cin >> n >> s >> x;
        vector<ll> arr(n + 1);
        ll total = 0;
        for (int i = 1; i <= n;i++)
        {
            cin >> arr[i];
            total += arr[i];
        }
        if(s>=total && ((s-total)%x==0))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
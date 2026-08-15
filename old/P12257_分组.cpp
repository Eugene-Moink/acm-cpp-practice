#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    if (n < 2) 
    {
        cout << 0 << endl;
        return 0;
    }

    ll mid = n / 2;
    ll l = 0;
    ll r = 1;
    ll group = 0;

    while (l < mid && r < n)
    {
        if(l>=r)
        {
            r = l + 1;
            continue;
        }

        if(arr[r]>=2*arr[l])
        {
            group++;
            l++;
            r++;
        }
        else
        {
            r++;
        }
       
    }
    

    cout << group << endl;
    return 0;
}
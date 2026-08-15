#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        vector<ll> arr(a);
        for (int i = 0; i < a;i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        ll ans=0;
        for (int i = 0; i < a;i+=2)
        {
            if(i+1<a)
            {
                ans = max(ans, abs(arr[i] - arr[i + 1]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}

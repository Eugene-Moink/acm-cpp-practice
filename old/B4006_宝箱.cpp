#include<bits/stdc++.h> 
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> arr;
    for (int i = 0; i < n;i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());

    ll sum = 0;
    ll ans = 0;
    ll l = 0;

    for (int r = 0; r < n;r++)
    {
        sum += arr[r];
        while(arr[r]-arr[l]>k)
        {
            sum -= arr[l];
            l++;
        }

        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    ll max_sum = 0;
    ll best_start = 0;

    for (ll i = 0; i < n;i++)
    {
        ll cur_sum = arr[i] + arr[(i + 1) % n] + arr[(i + 2) % n] + arr[(i + 3) % n];
        if (cur_sum > max_sum)
        {
            max_sum = cur_sum;
            best_start = i;
        }
    }

    cout << max_sum << endl;
    cout << best_start + 1 << endl;
}

int main()
{
    moink();
    return 0;
}
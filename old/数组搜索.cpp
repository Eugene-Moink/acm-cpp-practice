#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
ll n, m;
vector<ll> arr;
void moink()
{
    char op;
    ll num;
    cin >> op >> num;

    ll idx;
    if(op=='L')
    {
        idx = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
        if(idx==n||arr[idx]!=num)
        {
            cout << -1 << endl;
        }
        else
            cout << idx << endl;
    }

    else if(op=='R')
    {
        idx=upper_bound(arr.begin(), arr.end(), num) - arr.begin();
        if (idx == 0 || arr[idx - 1] != num)
        {
            cout << -1 << endl;
        }
        else
            cout << idx - 1 << endl;
    }

}

int main()
{
    cin >> n >> m;
    arr.resize(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    while(m--)
    {
        moink();
    }
    return 0;
}
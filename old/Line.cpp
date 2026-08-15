#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    vector<ll> get;
    ll cur = 0;
    for (int i = 0; i < n;i++)
    {
        ll left = i;
        ll right = n - 1 - i;
        if(s[i]=='L')
        {
            cur += left;
            get.push_back(right - left);
        }
        else
        {    
            cur += right;
            get.push_back(left - right);
        }
    }

    sort(get.rbegin(), get.rend());
    for (int k = 1; k <= n;k++)
    {
        if(k-1<get.size()&&get[k-1]>0)
        {
            cur += get[k - 1];
        }
        cout << cur << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}               
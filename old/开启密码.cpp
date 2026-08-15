#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> num(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());

    ll cnt = 1;
    ll max_cnt = 0;
    vector<ll> ans;
    for (ll i = 1; i < n;i++)
    {
        if (num[i] == num[i - 1])
        {
            cnt++;
        }
        else
        {
            if(cnt>max_cnt)
            {
                max_cnt = cnt;
                ans.clear();
                ans.push_back(num[i - 1]);
            }
            else if(cnt==max_cnt)
            {
                ans.push_back(num[i - 1]);
            }
            cnt = 1;
        }
    }

    if (cnt > max_cnt) 
    {
        max_cnt = cnt;
        ans.clear();
        ans.push_back(num[n - 1]);
    } 
    else if (cnt == max_cnt) 
    {
        ans.push_back(num[n - 1]);
    }

    for (ll x : ans)
    {
        cout << x << endl;
    }
}

int main()
{
    moink();
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<ll> arr(k, 0);
        for (int i = 0; i < n;i++)
        {
            ll group = i % k;
            if(s[i]=='1')
                arr[group]++;
        }

        bool poss = 1;
        for (int group = 0; group < k;group++)
        {
            if (arr[group] % 2 != 0)
            {
                poss = 0;
                break;
            }
        }
        cout << (poss ? "YES" : "NO") << endl;
    }
}
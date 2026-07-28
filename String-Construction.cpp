#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, k;
    cin >> n >> k;
    if(k>=n)
    {
        cout << "-1" << endl;
        return;
    }
    ll b = n - k;
    vector<ll> cand0;
    cand0.push_back(n / 2);
    if (n % 2 == 1)
        cand0.push_back((n + 1) / 2);

    bool ok = 0;
    char start_c;
    ll target0;

    for (char st : {'0', '1'})
    {
        ll b0, b1;
        if (st == '1')
        {
            b0 = b / 2;
            b1 = (b + 1) / 2;
        }
        else
        {
            b1 = b / 2;
            b0 = (b + 1) / 2;
        }
         for (ll c0 : cand0) 
         {
            if (c0 >= b0 && c0 <= n - b1)   
            {
                if ((b0 == 0 && c0 != 0) || (b1 == 0 && c0 != n)) 
                continue;

                ok = true;
                start_c = st;               
                target0 = c0;   
                break;
            }
        }
        if (ok) break;
    }

    if (!ok) 
    {   
        cout << "-1" << endl;
        return;
    }

    string ans;
    ll b0, b1;
    if (start_c == '0')
    {
        b0 = (b + 1) / 2;
        b1 = b / 2;
    }
    else 
    {
        b0 = b / 2;
        b1 = (b + 1) / 2;
    }
    ll extra0 = target0 - b0;
    ll extra1 = (n - target0) - b1;

    for (ll i = 0; i < b; i++) 
    {
        char cur = (i % 2 == 0) ? start_c : (start_c == '0' ? '1' : '0');
        ll len = 1;
        if (cur == '0' && extra0 > 0) 
        {
            len += extra0;
            extra0 = 0; 
        }
        if (cur == '1' && extra1 > 0) 
        {
            len += extra1;
            extra1 = 0;
        }
        ans += string(len, cur);
    }
    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
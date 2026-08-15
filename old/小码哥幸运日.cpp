#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll l, r;
    cin >> l >> r;
    ll cnt = 0;
    for (ll i = l; i <= r;i++)
    {
        string num = to_string(i);
        for (ll j = 0; j < num.size(); j++)
        {
            if (num[j] == '2')
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    moink();
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    ll n = s.size() + 1;
    vector<ll> a(n, 0);
    for (ll i = 0; i < n - 1;i++)
    {
        if(s[i]=='<')
        {
            a[i + 1] = a[i] + 1;
        }
    }
    for (ll i = n - 2; i >= 0;--i)
    {
        if(s[i]=='>')
        {
            a[i] = max(a[i], a[i + 1] + 1);
        }
    }

    ll sum = accumulate(a.begin(), a.end(), 0LL);
    cout << sum << endl;
}

int main()
{
    moink();
    return 0;
}
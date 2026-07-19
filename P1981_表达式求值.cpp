#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0, cur = 0;

    ll i = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
        cur = cur * 10 + (s[i] - '0');
        i++;
    }
    cur %= 10000;

    while (i < n)
    {
        char op = s[i];
        i++;

        ll num = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        num %= 10000;

        if (op == '+')
        {
            ans = (ans + cur) % 10000;
            cur = num;
        }
        else
        {
            cur = (cur * num) % 10000;
        }
    }

    ans = (ans + cur) % 10000;
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
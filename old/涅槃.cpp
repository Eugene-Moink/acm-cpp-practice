#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll product(ll x)
{
    ll ans = 1;
    while(x > 0)
    {
        ans *= (x % 10);
        x /= 10;
    }
    return ans;
}

void moink()
{
    ll n;
    cin >> n;
    string s = to_string(n);
    int len = s.size();

    ll ans = product(n);

    for (int i = 0; i < len;i++)
    {
        if(s[i] == '0')
            continue;

        string t = s;
        t[i]--;
        for (int j = i + 1; j < len;j++)
        {
            t[j] = '9';
        }
        ll new_num = stoll(t);
        ans = max(ans, product(new_num));
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
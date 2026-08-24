#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        sum += x;
    }

    string s = to_string(sum);
    ll max_val = sum;

    for (int len = 1; len <= k && len <= s.length(); len++)
    {
        for (int i = 0; i + len <= s.length(); i++)
        {
            string temp = s;
            reverse(temp.begin() + i, temp.begin() + i + len);
            ll nn = stoll(temp);
            max_val = max(max_val, nn);
        }
    }
    cout << max_val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
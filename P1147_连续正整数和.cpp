#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll number;
    cin >> number;
    vector<pair<ll, ll>> result;

    for (ll k = 2; k <= sqrt(number * 2);k++)
    {
        ll numerator = (2 * number) / k - k + 1;
        if(numerator > 0 && numerator % 2 == 0)
        {
            if ((2 * number) % k != 0) 
            continue;

            ll a = numerator / 2;

            if (a >= 1)
            {
                ll start = a;
                ll end = a + k - 1;
                result.push_back({start, end});
            }
        }
    }

    sort(result.begin(), result.end());

    for (auto& p : result)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
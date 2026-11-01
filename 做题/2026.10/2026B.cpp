#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n % 2 == 0)
    {
        ll ans = 0;
        for (int i = 0; i < n; i += 2)
        {
            ans = max(ans, a[i + 1] - a[i]);
        }
        cout << ans << '\n';
        return;
    }

    ll final_ans = 2e18;

    for (int i = 0; i < n; i++)
    {
        for (int d = -1; d <= 1; d += 2)
        {
            ll new_element = a[i] + d;

            bool exists = false;
            for (int j = 0; j < n; j++)
            {
                if (a[j] == new_element)
                {
                    exists = true;
                    break;
                }
            }
            if (exists)
                continue;

            vector<ll> b = a;
            b.push_back(new_element);
            sort(b.begin(), b.end());

            ll cur_max = 0;
            for (int j = 0; j < n + 1; j += 2)
            {
                cur_max = max(cur_max, b[j + 1] - b[j]);
            }

            final_ans = min(final_ans, cur_max);
        }
    }

    cout << final_ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
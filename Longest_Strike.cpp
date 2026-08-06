#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<ll> check;
    for (auto &p : cnt)
    {
        if(p.second >= k)
            check.push_back(p.first);
    }
    sort(check.begin(), check.end());
    if(check.empty())
    {
        cout << -1 << '\n';
        return;
    }

    int l = check[0];
    int ans = 0;
    int best_l = check[0], best_r = check[0];
    for (int i = 0; i + 1 < check.size();i++)
    {
        if(abs(check[i]-check[i+1])==1)
        {
            continue;
        }
        else
        {
            if (check[i] - l > best_r - best_l)
            {
                best_r = check[i];
                best_l = l;
            }
            l = check[i + 1];
        }
    }
    if (check.back() - l > best_r - best_l)
    {
        best_r = check.back();
        best_l = l;
    }
    cout << best_l << ' ' << best_r << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
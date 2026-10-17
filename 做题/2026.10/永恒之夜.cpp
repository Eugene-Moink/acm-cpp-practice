#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Person
{
    ll x, y;
    string name;
};

void solve()
{
    int n;
    ll R;
    cin >> n >> R;

    vector<Person> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].name;
    }

    vector<int> cnt(n, 0);

    ll R2 = R * R;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll dx = a[i].x - a[j].x;
            ll dy = a[i].y - a[j].y;
            if (dx * dx + dy * dy <= R2)
            {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    int mn = *min_element(cnt.begin(), cnt.end());

    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == mn)
        {
            cout << a[i].name << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
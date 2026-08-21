#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    set<ll> st;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        st.insert(x);
    }

    ll cur = 0;
    ll ans = 0;
    while (!st.empty())
    {
        auto it = st.lower_bound(cur);
        ll right = (it == st.end() ? (ll)4e18 : *it);
        ll left = (it == st.begin() ? (ll)4e18 : *prev(it));

        ll d_left = (left == 4e18 ? 4e18 : llabs(left - cur));
        ll d_right = (right == 4e18 ? 4e18 : llabs(right - cur));

        if (d_left <= d_right)
        {
            ans += d_left;
            cur = left;
            st.erase(left);
        }
        else
        {
            ans += d_right;
            cur = right;
            st.erase(right);
        }
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
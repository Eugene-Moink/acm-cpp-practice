#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s, t;
    cin >> s >> t;
    string cur_num = s + t;
    ll cur = stoll(cur_num);
    ll tmp = sqrt(cur);
    if (tmp * tmp == cur)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
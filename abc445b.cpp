#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (string &str : s)
        cin >> str;

    int max_s = 0;
    for (string str : s)
        max_s = max(max_s, (int)str.size());

    for (string str : s)
    {
        int k = (max_s - (int)str.size()) / 2;
        if (k == 0)
            cout << str << '\n';
        else
            cout << string(k, '.') << str << string(k, '.') << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
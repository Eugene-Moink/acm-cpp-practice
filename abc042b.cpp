#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<string> str(n);
    for (string &s : str)
        cin >> s;

    sort(str.begin(), str.end());
    for (string s : str)
        cout << s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
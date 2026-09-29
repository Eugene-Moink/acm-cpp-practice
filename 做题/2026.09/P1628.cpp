#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (string &s : str)
        cin >> s;

    string T;
    cin >> T;
    vector<string> ans;
    for (string s : str)
    {
        if (s.size() >= T.size() && s.substr(0, T.size()) == T)
            ans.push_back(s);
    }
    sort(ans.begin(), ans.end());

    for (string s : ans)
    {
        cout << s << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
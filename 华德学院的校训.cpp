#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

string s = "chengyi qiuzhen duxue qiangji";

void solve()
{
    string a;
    getline(cin, a);
    if (a == s)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    cin.ignore();

    while (t--)
    {
        solve();
    }
    return 0;
}
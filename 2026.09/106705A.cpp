#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string a, b;
    cin >> a >> b;
    map<string, string> str;
    str["fu"] = "quan";
    str["zhi"] = "jin";
    str["si"] = "nan";
    str["da"] = "fang";
    str["pu"] = "ding";
    str["li"] = "ping";
    str["shi"] = "qian";
    str["zhen"] = "feng";

    if (str[a] == b || (a == "an" && (b == "shun" || b == "long")))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
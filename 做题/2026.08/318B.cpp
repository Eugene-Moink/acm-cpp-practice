#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    cin >> s;
    ll ans = 0;
    ll heavy_cnt = 0;
    for (int i = 0; i + 5 <= (int)s.size(); i++)
    {
        string temp = s.substr(i, 5);
        if (temp == "heavy")
            heavy_cnt++;
        else if (temp == "metal")
            ans += heavy_cnt;
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
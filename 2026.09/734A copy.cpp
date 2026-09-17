#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (char c : s)
    {
        if (c == 'A')
            cnt1++;
        if (c == 'D')
            cnt2++;
    }

    if (cnt1 > cnt2)
        cout << "Anton\n";
    else if (cnt1 < cnt2)
        cout << "Danik\n";
    else if (cnt1 == cnt2)
        cout << "Friendship\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
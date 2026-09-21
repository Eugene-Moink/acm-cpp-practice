#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (string &w : words)
        cin >> w;

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string text;
    getline(cin, text);

    int cnt = 0;
    string ans = "";
    for (int i = 0; i < (int)text.size();)
    {
        bool matched = false;
        for (string &w : words)
        {
            int len = (int)w.size();
            if (i + len <= (int)text.size() && text.substr(i, len) == w)
            {
                ans += "<censored>";
                cnt++;
                i += len;
                matched = true;
                break;
            }
        }
        if (!matched)
        {
            ans += text[i];
            i++;
        }
    }

    if (cnt < k)
        cout << ans << '\n';
    else
        cout << cnt << '\n'
             << "He Xie Ni Quan Jia!" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
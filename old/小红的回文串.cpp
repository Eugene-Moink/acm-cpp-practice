#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(26, 0);
    int ans=0;
    for (char c : s) 
        cnt[c - 'a']++;

    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] == 0)
        continue;

        char del = 'a' + i;
        int l = 0, r = n - 1;
        bool ok = 1;

        while (l < r)
        {
            if (s[l] == del)
            {
                l++;
                continue;
            }

            if(s[r] == del)
            {
                r--;
                continue;
            }

            if(s[l] != s[r])
            {
                ok = 0;
                break;
            }
            l++, r--;
        }
        if(ok)
            ans++;
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
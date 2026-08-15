#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n;i++)
    {
        if(s[i]=='1')
            cnt1++;
        else
            cnt0++;
    }

    if(abs(cnt1-cnt0)>2)
    {
        cout << -1 << '\n';
        return;
    }

    int ans = n;
    for (int start = 0; start <= 1;start++)
    {
        vector<int> match;
        int need = start;
        for(char c : s)
        {
            if (c - '0' == need)
            {
                match.push_back(need);
                need = 1 - need;
            }
        }

        int total = match.size();
        int keep0 = count(match.begin(), match.end(), 0);
        int keep1 = total - keep0;

        while(total>0)
        {
            if (abs((cnt0 - keep0) - (cnt1 - keep1)) <= 1)
            {
                ans = min(ans, n - total);
            }

            int last = match.back();
            if(last==0)
                keep0--;
            else
                keep1--;
            match.pop_back();
            total--;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
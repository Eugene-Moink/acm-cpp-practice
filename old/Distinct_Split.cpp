#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> pre(n), suf(n);
    vector<int> cnt(26, 0);

    int dist = 0;
    for (int i = 0; i < n;i++)
    {
        int idx = s[i] - 'a';
        if(cnt[idx]==0)
        {
            dist++;
        }
        cnt[idx]++;
        pre[i] = dist;
    }

    dist = 0;
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = n - 1; i >= 0;i--)
    {
        int idx = s[i] - 'a';
        if(cnt[idx]==0)
        {
            dist++;
        }
        cnt[idx]++;
        suf[i] = dist;
    }

    int ans = 0;
    for (int i = 0; i + 1 < n;i++)
    {
        ans = max(ans, pre[i] + suf[i + 1]);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
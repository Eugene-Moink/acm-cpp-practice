#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
    }

    int l = 0, ans = 0;
    unordered_map<int, int> cnt;
    for (int r = 0; r < n;r++)
    {
        cnt[a[r]]++;
        while(cnt[a[r]]>1)
        {
            cnt[a[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
     cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
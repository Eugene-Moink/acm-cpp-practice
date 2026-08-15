#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1,0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    

    vector<int> freq;
    for (int i = 1; i <= n; i++) 
    {
        if (a[i]) freq.push_back(a[i]);
    }
    sort(freq.begin(), freq.end());
    if ((int)freq.size() <= k) 
        cout << 0;
    else 
    {
        int ans = 0;
        for (int i = 0; i < (int)freq.size() - k; i++) 
        ans += freq[i];
        cout << ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
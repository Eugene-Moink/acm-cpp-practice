#include<bits/stdc++.h>
using ll = long long;
using namespace std;
void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int val_max = INT_MIN, val_min = INT_MAX;
    int pos_max = -1, pos_min = -1;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
        if(a[i]>val_max)
        {
            val_max = a[i];
            pos_max = i;
        }
        if(a[i]<val_min)
        {
            val_min = a[i];
            pos_min = i;
        }
    }

    int l = min(pos_max, pos_min);
    int r = max(pos_max, pos_min);

    int left = r + 1;
    int right = n - l;
    int both = (l + 1) + (n - r);

    int ans = min({left, right, both});
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
}
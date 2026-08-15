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
        cin >> a[i];

    vector<int> left_1(n, 0);
    int cnt_1 = 0, base = 0;
    for (int i = 0; i < n;i++)
    {
        left_1[i] = cnt_1;
        if(a[i]==1)
        {
            cnt_1++;
        }
        else
        {
            base += cnt_1;
        }
    }

    vector<int> right_0(n, 0);
    int cnt_0 = 0;
    for (int i = n - 1; i >= 0;i--)
    {
        right_0[i] = cnt_0;
        if(a[i]==0)
            cnt_0++;
    }

    ll ans = base;
    for (int i = 0; i < n;i++)
    {
        ll new_sc = base;
        if(a[i]==1)
        {
            new_sc = base - right_0[i] + left_1[i];
        }
        else
        {
            new_sc = base + right_0[i] - left_1[i];
        }
        ans = max(ans, new_sc);
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
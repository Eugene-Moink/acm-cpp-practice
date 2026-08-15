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

    int l = 0, r = n - 1;
    int sum_l = 0, sum_r = 0, ans = 0;
    while(l<=r)
    {
        if(sum_l<sum_r)
        {
            sum_l += a[l++];
        }
        else if(sum_l>sum_r)
        {
            sum_r += a[r--];
        }
        else
        {
            ans = max(ans, l + (n - 1 - r));
            if (l < r) 
            {
                sum_l += a[l++];
            } 
            else 
            {
                break;
            }
        }
    }
    if (sum_l == sum_r) 
    {
         ans = max(ans, l + (n - 1 - r));
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
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

    int cnt_odd = 0, cnt_even = 0;
    for (int i = 0; i < n;i++)
    {
        if (a[i] % 2 == 0)
            cnt_even++;
        else
            cnt_odd++;
    }
    if (cnt_even == n || cnt_odd == n)
    {
        for(int x : a)
        {
            cout << x << " ";
        }
    }
    else
    {
        sort(a.begin(), a.end());
        for(int x : a)
        {
            cout << x << " ";
        }
    }
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
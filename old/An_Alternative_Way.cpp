#include<bits/stdc++.h>
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < n;i++)
        cin >> b[i];

    ll ex = 0;
    for (int i = n - 1; i >= 0;i--)
    {
        ll cur = a[i] + ex;
        if(i==0)
        {
            if(cur>b[i])
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            if(cur>b[i])
            {
                ex = cur - b[i];
            }
            else
            {
                ex = 0;
            }
        }
    }
    cout << "YES" << endl;
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
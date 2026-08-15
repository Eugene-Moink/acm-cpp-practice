#include<bits/stdc++.h>
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

    vector<int> tail;
    for (int x : a)
    {
        auto it = upper_bound(tail.begin(), tail.end(), x);
        if(it == tail.end())
        {
            tail.push_back(x);
        }
        else
        {
            *it = x;
        }
    }
    int lnds_len = (int)tail.size();
    cout << n - lnds_len << endl;
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
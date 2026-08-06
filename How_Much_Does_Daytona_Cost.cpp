#include<bits/stdc++.h>
using ll = long long;
using namespace std;
void moink()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        if(x == k &&cnt >= 2)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "NO\n";
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

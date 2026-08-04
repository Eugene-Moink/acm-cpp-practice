#include<bits/stdc++.h>
using ll = long long;
using namespace std;
void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int odd=0, even = 0;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
        if(a[i]%2==0)
            even++;
        else
            odd++;
    }

    if (odd == 0)
    {
        cout << "NO\n";
    }
    else if (odd == n)
    {
        if (n % 2 == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "YES\n";
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

#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int oddParity = a[0] % 2;
    for (int i = 2; i < n; i += 2) 
    {
        if (a[i] % 2 != oddParity) 
        {
            cout << "NO" << endl;
            return;
        }
    }

    int evenParity = a[1] % 2;
    for (int i = 3; i < n; i += 2) 
    {
        if (a[i] % 2 != evenParity) 
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
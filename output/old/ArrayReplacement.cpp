#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    for (int i = 0; i < n; ) 
    {
        int j = i;
        while (j + 1 < n && (a[j] & 1) == (a[j+1] & 1)) 
            j++;
        
        if (j - i + 1 >= 3) 
        {
            for (int k = i + 1; k <= j; k++) 
            {
                a[k] = a[k-1] - 2;
            }
        }
        i = j + 1;
    }
    for(int x : a)
    {
        cout << x << " ";
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    int b;
    cin >> b;
    int last = min(a[0], b - a[0]);
    for (int i = 1; i < n;i++)
    {
        int x1 = a[i];
        int x2 = b - a[i];

        if (x1 < last &&x2 < last)
        {
            cout << "No" << endl;
            return;
        }

        if (x1 >= last &&x2 >= last)
        {
            last = min(x1, x2);
        }

        else if (x1 >= last)
        {
            last = x1;
        }

        else
        {
            last = x2;
        }
    }
    cout << "Yes" << endl;
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
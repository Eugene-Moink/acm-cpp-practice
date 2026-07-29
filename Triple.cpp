#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n;i++)
    {
        int num;
        cin >> num;
        a[num]++;
    }

    bool ok = 0;
    for (int i = 1; i <= n;i++)
    {
        if(a[i]>=3)
        {
            ok = 1;
            cout << i << endl;
            break;
        }
    }
    if(!ok)
    {
        cout << -1 << endl;
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
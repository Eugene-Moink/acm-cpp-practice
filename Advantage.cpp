#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int max1 = -1, max2 = -1, cnt = 0;
    for (int i = 0; i < n;i++)
    { 
        cin >> a[i];
        if(a[i]>max1)
        {
            max2 = max1;
            max1 = a[i];
            cnt = 1;
        }
        else if(a[i]==max1)
        {
            cnt++;
        }
        else if(a[i]>max2)
        {
            max2 = a[i];
        }
    }

    for (int i = 0; i < n;i++)
    {
        if(a[i]==max1)
        {
            if(cnt>1)
            {
                cout << 0;
            }
            else
            {
                cout << a[i] - max2;
            }
        }
        else
        {
            cout << a[i] - max1;
        }

        if (i < n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
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
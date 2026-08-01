#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int valley_cnt = 0;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j + 1 < n && a[j] == a[j + 1])
        {
            j++;
        }

        bool left = (i == 0) || (a[i - 1] > a[i]);
        bool right = (j == n - 1) || (a[j] < a[j + 1]);

        if (left &&right)
        {
            valley_cnt++;
        }

        i = j + 1;
    }
    if(valley_cnt==1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        moink();
    }
    return 0;
}
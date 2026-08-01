#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int len = 1;
    int max_len = -1;
    for (int i = 1; i < n;i++)
    {
        if (a[i] - a[i - 1] <= k)
        {
            len++;
        }
        else
        {
            max_len = max(max_len, len);
            len = 1;
        }
    }
    max_len = max(max_len, len);
    cout << n - max_len << endl;
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
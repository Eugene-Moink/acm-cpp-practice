#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 10 != 0)
    {
        cout << sum << endl;
        return;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n;i++)
    {
        if ((sum - a[i]) % 10 != 0)
        {
            cout << sum - a[i] << endl;
            return;
        }
    }

    cout << 0 << endl;
}

int main()
{
    moink();
    return 0;
}
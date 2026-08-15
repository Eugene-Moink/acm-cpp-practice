#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> need(n);
    for (int i = 0; i < n;i++)
    {
        cin >> need[i];
    }
    sort(need.begin(), need.end());

    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        if (m >= need[i])
        {
            ans++;
            m -= need[i];
        }

        else if (k > 0)
        {
            ans++;
            k--;
        }

        else
        {
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}
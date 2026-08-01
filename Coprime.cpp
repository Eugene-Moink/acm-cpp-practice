#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> first(1005, 0), second(1005, 0); 
    
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i > first[x]) 
        {
            second[x] = first[x];
            first[x] = i;
        } 
        else if (i > second[x]) 
        {
            second[x] = i;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++) 
    {
        for (int j = 1; j <= 1000; j++)
        {
            if (first[i] == 0 || first[j] == 0) continue;

            if (__gcd(i, j) == 1)
            {
                if (i == j) 
                {
                    if (second[i] == 0) continue;
                    ans = max(ans, first[i] + second[i]);
                }
                else 
                {
                    ans = max(ans, first[i] + first[j]);
                }
            }
        }
    }

    if (ans == 0) cout << -1 << endl; 
    else cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> dY(n + 3, 0), dB(n + 3, 0), dR(n + 3, 0);

    for (int i = 0; i < m; i++) 
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (k == 1) 
        { 
            dY[l]++;
            dY[r + 1]--;
        }
        else if (k == 2)
        { 
            dB[l]++;
            dB[r + 1]--;
        }
        else 
        { 
            dR[l]++;
            dR[r + 1]--;
        }
    }

    long long ans = 0;
    int y = 0, b = 0, r = 0;
    for (int i = 1; i <= n; i++) 
    {
        y += dY[i];
        b += dB[i];
        r += dR[i];
        if (y > 0 && b > 0 && r == 0) 
        ans++;
    }

    cout << ans << endl;
    return 0;
}
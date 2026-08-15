#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int n, m;
   
    ll result = LLONG_MAX;
    cin >> n >> m;

    vector<int> costW(n+1), costB(n+1), costR(n+1);

    for (int i = 1; i <= n; i++) 
    {
        string s;
        cin >> s;

        int cntW = 0, cntB = 0, cntR = 0; 
        for (char c : s) 
        {
            if (c == 'W') cntW++;
            else if (c == 'B') cntB++;
            else cntR++;
        }

        costW[i] = m - cntW;  
        costB[i] = m - cntB;  
        costR[i] = m - cntR;  
    }

    vector<int> preW(n+1,0), preB(n+1,0), preR(n+1,0);
    for (int i = 1; i <= n; i++) 
    {
        preW[i] = preW[i-1] + costW[i];
        preB[i] = preB[i-1] + costB[i];
        preR[i] = preR[i-1] + costR[i];
    }

    for (int a = 1; a <= n - 2; a++) 
    {
        for (int b = a + 1; b <= n - 1; b++) 
        {
            ll total = preW[a] + (preB[b] - preB[a]) + (preR[n] - preR[b]);
            result = min(result, total);
        }
    }

    cout << result << endl;
    return 0;
}
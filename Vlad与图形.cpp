#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++)    
        {
            string row;
            cin >> row;
            for (char c : row) if (c == '1') cnt[i]++;
        }

        int L = -1, R = -1;
        for (int i = 0; i < n; i++) 
        {
            if (cnt[i] > 0) 
            {
                if (L == -1) L = i;
                R = i;
            }
        }

        bool square = true;
        int val = cnt[L];
        for (int i = L; i <= R; i++)
         {
            if (cnt[i] != val) 
            {
                square = false;
                break;
            }
        }

        cout << (square ? "SQUARE" : "TRIANGLE") << endl;
    }
}
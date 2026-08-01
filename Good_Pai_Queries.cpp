#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;

    vector<int> preA(n + 1), preB(n + 1), preC(n + 1), preD(n + 1);
    for (int i = 1; i <= n;i++)
    {
        preA[i] = preA[i - 1];
        preB[i] = preB[i - 1];
        preC[i] = preC[i - 1];
        preD[i] = preD[i - 1];

        if (s[i-1] == '0' && t[i-1] == '0')
            preA[i]++;
        else if (s[i-1] == '1' && t[i-1] == '1')
            preB[i]++;
        else if (s[i-1] == '0' && t[i-1] == '1')
            preC[i]++;
        else
            preD[i]++;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int a = preA[r] - preA[l-1];
        int b = preB[r] - preB[l-1];
        int c = preC[r] - preC[l-1];
        int d = preD[r] - preD[l-1];

        int good = a + b;
        int diff = abs(c - d);

        if (good >= diff)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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
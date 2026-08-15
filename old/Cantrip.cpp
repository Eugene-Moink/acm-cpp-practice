#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> pre_o(n + 1, 0);
    for (int i = 0; i < n;i++)
    {
        pre_o[i + 1] = pre_o[i] + (s[i] == 'o');
    }

    vector<int> pos_x;
    for (int i = 0; i < n;i++)
    {
        if(s[i]=='x')
        {
            pos_x.push_back(i);
        }
    }

    for (int k = 1; k <= n;k++)
    {
        int e = pre_o[k];

        int idx = lower_bound(pos_x.begin(), pos_x.end(), k) - pos_x.begin();
        int remind_x = (int)pos_x.size() - idx;

        if(e==0)
            cout << k << endl;
        else if (remind_x < e)
            cout << n << endl;
        else
        {
            int end_idx = pos_x[idx + e - 1];
            cout << k + (end_idx - k + 1) << endl;
        }
    }
}

int main()
{
    moink();
    return 0;
}
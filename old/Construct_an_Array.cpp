#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> cons;
    vector<int> sgn(n, -1);
    bool ok = true;

    for(int k=0; k<m; ++k)
    {
        int o, i, j;
        cin >> o >> i >> j;
        --i; --j;
        cons.push_back({o,i,j});
        if(i == j)
        {
            int need = (o == 1 ? 0 : 1);
            if(sgn[i] == -1) sgn[i] = need;
            else if(sgn[i] != need) ok = false;
        }
    }

    if(!ok)
    {
        cout << "No" << endl;
        return;
    }

    for(auto &[o,i,j] : cons)
    {
        if(i == j) continue;
        if(sgn[i] == -1) sgn[i] = 0;
        if(sgn[j] == -1) sgn[j] = 0;

        if(sgn[i] == 0 && sgn[j] == 0)
        {
            if(o == 2) ok = false;
        }
        else if(sgn[i] == 1 && sgn[j] == 1)
        {
            if(o == 1) ok = false;
        }
        else if(sgn[i] == 0 && sgn[j] == 1)
        {
            if(o == 1) ok = false;
        }
        else if(sgn[i] == 1 && sgn[j] == 0)
        {
            if(o == 2) ok = false;
        }
        if(!ok) break;
    }

    if(!ok)
    {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    for(int i=0; i<n; ++i)
    {
        ll val;
        if(sgn[i] == 0) val = 1000000000LL + i + 1;
        else val = -(1000000000LL + i + 1);
        cout << val << (i==n-1 ? "\n" : " ");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
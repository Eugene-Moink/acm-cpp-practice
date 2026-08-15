#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string y, m, d;
        cin >> y >> m >> d;

        ll y_num = 0, m_num = 0, d_num = 0;
        for (int i = 0; i < y.size();i++)
        {
            y_num += y[i] - '0';
        }

        for (int i = 0; i < m.size();i++)
        {
            m_num += m[i] - '0';
        }

        for (int i = 0; i < d.size();i++)
        {
            d_num += d[i] - '0';
        }

        if(y_num==d_num&&d_num==m_num)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
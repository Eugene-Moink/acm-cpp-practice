#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, m, h;
    cin >> n >> m >> h;
    vector<ll> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    vector<ll> val(n);
    vector<int> last_ver(n, -1);
    int ver = 0;
    while(m--)
    {
        int pos;
        ll c;
        cin >> pos >> c;
        pos--;

        ll cur;
        if (last_ver[pos] < ver)
        {
            cur = a[pos];
        }
        else
        {
            cur = val[pos];
        }

        ll new_val = cur + c;
        if(new_val>h)
        {
            ver++;
        }
        else
        {
            last_ver[pos] = ver;
            val[pos] = new_val;
        }
    }

    for (int i = 0; i < n;i++)
    {
        if(last_ver[i]<ver)
            cout << a[i];
        else
            cout << val[i] << endl;

        if (i < n - 1)
            cout << " ";
    }
    cout << endl;
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
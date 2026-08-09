#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int q;
    cin >> q;

    ll xor_sum = 0;
    vector<int> pos;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            xor_sum ^= a[x]; 
            a[x]++;
            xor_sum ^= a[x]; 
            if (a[x] == 1) pos.push_back(x);
        }
        else 
        {
            vector<int> new_pos;
            for (int p : pos)
            {
                xor_sum ^= a[p]; 
                a[p]--;
                xor_sum ^= a[p]; 
                if (a[p] > 0) new_pos.push_back(p);
            }
            pos.swap(new_pos);
        }
        cout << xor_sum << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
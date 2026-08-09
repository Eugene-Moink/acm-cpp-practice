#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
            odd++;
        else
            even++;
    }

    if(odd != 0 && even != 0)
    {
        sort(a.begin(), a.end());
        for(int x : a)
        {
            cout << x << " ";
        }
        cout << '\n';
        return;
    }

    else
    {
        for(int x : a)
        {
            cout << x << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
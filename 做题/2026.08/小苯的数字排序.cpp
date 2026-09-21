#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    for (int x : even)
        cout << x << " ";
    for (int x : odd)
        cout << x << " ";

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}
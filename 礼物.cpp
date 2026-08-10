#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 2, vector<int>(4));
    for (int i = 1; i <= n; i++)
    {
        int a, b, g, k;
        cin >> a >> b >> g >> k;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = g;
        arr[i][3] = k;
    }

    int x, y;
    cin >> x >> y;
    for (int i = n; i >= 1; i--)
    {
        if ((x >= arr[i][0] && x <= arr[i][0] + arr[i][2]) && (y >= arr[i][1] && y <= arr[i][1] + arr[i][3]))
        {
            cout << i << '\n';
            return;
        }
    }

    cout << -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
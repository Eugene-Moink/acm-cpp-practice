#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int n;
            cin >> n;
            if (n == 0)
                cout << '.';
            else
                cout << (char)('A' + n - 1);
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
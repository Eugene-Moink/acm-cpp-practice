#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    for (int r = 0; r * R <= N; r++)
    {
        int rem1 = N - r * R;
        for (int g = 0; g * G <= rem1; g++)
        {
            int rem2 = rem1 - g * G;
            if (rem2 % B == 0)
                ans++;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
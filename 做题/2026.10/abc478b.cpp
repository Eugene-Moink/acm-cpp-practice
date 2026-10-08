#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, V;
    cin >> N >> V;
    vector<int> W(N);
    for (int i = 0; i < N; i++)
        cin >> W[i];

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int price = (i + 1) + (j + 1) + (k + 1);
                if (price <= V)
                {
                    int happiness = W[i] + W[j] + W[k];
                    ans = max(ans, happiness);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
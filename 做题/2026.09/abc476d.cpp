#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int N, M;
    ll K;
    cin >> N >> M >> K;

    ll X, Y;
    cin >> X >> Y;

    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<ll> prefA(N + 1, 0);
    for (int i = 0; i < N; i++)
        prefA[i + 1] = prefA[i] + A[i];

    ll ans = 0;
    ll prefB_K = 0;
    ll prefB_sum = 0;

    for (int j = 0; j <= M; j++)
    {
        if (j > 0)
        {
            prefB_K += (B[j - 1] + K - 1) / K;
            prefB_sum += B[j - 1];
        }
        if (prefB_K > Y)
            break;

        ll total = X + Y * K - prefB_sum;
        int i = upper_bound(prefA.begin(), prefA.end(), total) - prefA.begin() - 1;
        if (i < 0)
            i = 0;
        ans = max(ans, (ll)i + j);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
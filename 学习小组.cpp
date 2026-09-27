#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll current_sum = 0;
    for (int i = 0; i < K; i++)
    {
        current_sum += A[i];
    }

    ll max_sum = current_sum;

    for (int i = K; i < N; i++)
    {
        current_sum += A[i];
        current_sum -= A[i - K];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
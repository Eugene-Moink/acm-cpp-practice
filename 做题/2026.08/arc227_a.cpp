#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> get_positions(const string &s)
{
    vector<int> pos;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == '1')
            pos.push_back(i);
    }
    return pos;
}

void moink()
{
    int N;
    cin >> N;
    string A, B, C;
    cin >> A >> B >> C;

    vector<int> pA = get_positions(A);
    vector<int> pB = get_positions(B);
    vector<int> pC = get_positions(C);

    vector<int> X_pos(N);
    ll K = 0;

    for (int i = 0; i < N; ++i)
    {
        int a = pA[i], b = pB[i], c = pC[i];
        int arr[3] = {a, b, c};
        sort(arr, arr + 3);
        int median = arr[1];

        X_pos[i] = median;
        K += llabs(a - median) + llabs(b - median) + llabs(c - median);
    }

    string X(2 * N, '0');
    for (int pos : X_pos)
        X[pos] = '1';

    cout << K << '\n'
         << X << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int N, N_a, N_b;
    cin >> N >> N_a >> N_b;

    vector<int> a(N_a);
    for (int i = 0; i < N_a; ++i)
    {
        cin >> a[i];
    }

    vector<int> b(N_b);
    for (int i = 0; i < N_b; ++i)
    {
        cin >> b[i];
    }

    int table[5][5] = {
        {0, -1, 1, 1, -1},
        {1, 0, -1, 1, -1},
        {-1, 1, 0, -1, 1},
        {-1, -1, 1, 0, 1},
        {1, 1, -1, -1, 0}};

    int sc_a = 0, sc_b = 0;
    for (int i = 0; i < N; ++i)
    {
        int x = a[i % N_a];
        int y = b[i % N_b];
        if (table[x][y] == 1)
            sc_a++;
        else if (table[x][y] == -1)
            sc_b++;
    }
    cout << sc_a << " " << sc_b << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
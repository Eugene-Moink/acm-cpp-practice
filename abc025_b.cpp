#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int N, A, B;
    cin >> N >> A >> B;

    int pos = 0;
    while (N--)
    {
        string dir;
        int d;
        cin >> dir >> d;

        int move;
        if (d < A)
            move = A;
        else if (d > B)
            move = B;
        else
            move = d;

        if (dir == "East")
            pos += move;
        else
            pos -= move;
    }

    if (pos > 0)
        cout << "East " << pos << '\n';
    else if (pos < 0)
        cout << "West " << -pos << '\n';
    else
        cout << 0 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
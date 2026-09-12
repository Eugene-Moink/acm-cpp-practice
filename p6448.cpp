#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[5];

bool check()
{
    for (int i = 0; i < 5; i++)
    {
        if (a[i] != i + 1)
            return false;
    }
    return true;
}

void print_a()
{
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " \n"[i == 4];
    }
}

void solve()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    while (!check())
    {
        if (a[0] > a[1])
        {
            swap(a[0], a[1]);
            print_a();
        }

        if (a[1] > a[2])
        {
            swap(a[1], a[2]);
            print_a();
        }

        if (a[2] > a[3])
        {
            swap(a[2], a[3]);
            print_a();
        }

        if (a[3] > a[4])
        {
            swap(a[3], a[4]);
            print_a();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
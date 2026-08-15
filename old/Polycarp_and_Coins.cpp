#include<bits/stdc++.h>
using ll = long long;
using namespace std;
void moink()
{
    int n;
    cin >> n;
    int x1 = n / 3;
    int x2 = x1 + 1;

    int best = x1;
    if (n - 2 *x2 >= 0 &&abs(n - 3 * x2) < abs(n - 3 * best))
    {
        best = x2;
    }

    int c2 = best;
    int c1 = n - 2 * c2;
    cout << c1 << ' ' << c2 << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
}
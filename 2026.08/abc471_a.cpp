#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int a, b;
    cin >> a >> b;
    if (a + b == 9 || a - b == 9 || a * b == 9 || a == 9 * b)
        cout << "Nine\n";
    else
        cout << "Nein\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
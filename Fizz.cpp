#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {

        if(i%3==0)
            cout << "Fizz\n";
        else
            cout << i << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string get_mask(int n)
{
    string res = "";
    while (n > 0)
    {
        int digit = n % 10;
        if (digit == 4 || digit == 7)
        {
            res += (char)('0' + digit);
        }
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

void moink()
{
    int a, b;
    cin >> a >> b;
    string target = to_string(b);
    for (int c = a + 1;; c++)
    {
        if (get_mask(c) == target)
        {
            cout << c << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}
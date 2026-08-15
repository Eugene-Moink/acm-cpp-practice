#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool good(int x) 
{
    while (x > 0) 
    {
        int d = x % 10;
        if (d == 3 || d == 7) return false;
        x /= 10;
    }
    return true;
}

int main()
{
    ll result = 0;

    ll number;
    cin >> number;

    for (int a = 1; a <= number;a++)
    {
        for (int b = a + 1; b < number;b++)
        {
            ll c = number - a - b;
            if (c <= b) continue;
            if (good(a) && good(b) && good(c)) 
            result++;
        }
    }

    cout << result;
    return 0;
}
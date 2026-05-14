#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    long long number;
    cin >> number;
    vector<pair<long long, long long>> result;

    for (long long k = 2; k <= sqrt(number * 2);k++)
    {
        long long numerator = (2 * number) / k - k + 1;
        if(numerator > 0 && numerator % 2 == 0)
        {
            if ((2 * number) % k != 0) continue;
            long long a = numerator / 2;
            if (a >= 1)
            {
                long long start = a;
                long long end = a + k - 1;
                result.push_back({start, end});
            }
        }
    }

    sort(result.begin(), result.end());

    for (auto& p : result)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        long long n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;

        long long diff = abs(x1 - x2);
        long long initial_dist = min(diff, n - diff);
        long long result = k + initial_dist;
        
        cout << result << endl;
    }
    return 0;
}
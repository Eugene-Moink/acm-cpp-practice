#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;

    long long result = 0;
    while(m--&&n>=3)
    {
        int temp = n / 3;
        result += temp;
        n -= temp;
       
    }

    cout << result << endl;
    return 0;
}
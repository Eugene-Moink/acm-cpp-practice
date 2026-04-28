#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> temp(n+1);
    for (int i = 1; i <= n;i++)
    {
        cin >> temp[i];
    }

    vector<long long> prefix(n+1);
    prefix[0] = 0;
    for (int j = 1; j <= n;j++)
    {
        prefix[j] = prefix[j - 1] + temp[j];
    }
    long long min_sum = LLONG_MAX;

    for (int k = 1; k <= n - m + 1;k++)
    {
        long long temp_num = prefix[k + m - 1] - prefix[k - 1];
        min_sum = min(min_sum, temp_num);
    }

    cout << min_sum << endl;
    return 0;
}
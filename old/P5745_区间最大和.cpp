#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    vector<long long> number(n + 1, 0);
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> number[i];
        prefix[i] = prefix[i - 1] + number[i];
    }

    long long best_sum = -1;
    int best_l = 1, best_r = 1;
    int l = 1;
    
    for (int r = 1; r <= n; r++) 
    {
        while (l <= r && prefix[r] - prefix[l-1] > m) 
        {
            l++;
        }

        if (l <= r) 
        {
            long long cur_sum = prefix[r] - prefix[l-1];
            if (cur_sum > best_sum || (cur_sum == best_sum && l < best_l)) 
            {
                best_sum = cur_sum;
                best_l = l;
                best_r = r;
            }
        }
    }

    cout << best_l << " " << best_r << " " << best_sum;
    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> number(n);
    for (int i = 0; i < n; i++)
    {
        int temp_number;
        cin >> temp_number;
        number[i] = temp_number;
    }

    sort(number.begin(), number.end());

    for (int j = 1; j <= q; j++)
    {
        int need_number;
        cin >> need_number;
        
        int min_greater = -1;
        int max_less = -1;
        
        auto itGreater = upper_bound(number.begin(), number.end(), need_number);
        if (itGreater != number.end())
        {
            min_greater = *itGreater;
        }

        auto itLess = lower_bound(number.begin(), number.end(), need_number);
        if (itLess != number.begin())
        {
            --itLess;
            max_less = *itLess;
        }
        
        cout << min_greater << " " << max_less << endl;
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int zero_cnt = 0;
        int zero_idx = 0;
        for (int i = 0; i < n;i++)
        {
            cin >> arr[i];
            if(arr[i]==0)
            {
                zero_cnt++;
                zero_idx = i;
            }
        }

        if(zero_cnt>=2)
        {
            cout << "0" << endl;
            continue;
        }

        int idx;
        if (zero_cnt==1) idx = zero_idx;
        else idx = 0; 
        
        if(zero_cnt==0)
        {
            
            for (int i = 0; i < n;i++)
            {
                if(arr[i]<arr[idx])
                {
                    idx = i;
                }
            }
        }

        ll result = 1;
        for (int i = 0; i < n;i++)
        {
            if(i==idx)
            {
                arr[i]++;
            }
            result *= arr[i];
        }
        cout << result << endl;
    }
    return 0;
}
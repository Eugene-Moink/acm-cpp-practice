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

    for (int j = 1; j <= q; j++)
    {
        int need_number;
        cin >> need_number;
        
        int min_greater = -1;
        int max_less = -1;
        
        for (int k = 0; k < number.size(); k++)
        {
            if (number[k] > need_number)
            {
                if (min_greater == -1 || number[k] < min_greater) 
                {
                    min_greater = number[k];
                }
            }
            if (number[k] < need_number) 
            {
                if (max_less == -1 || number[k] > max_less) 
                {
                    max_less = number[k];
                }
            }
        }
        
        cout << min_greater << " " << max_less << endl;
    }
    
    return 0;
}
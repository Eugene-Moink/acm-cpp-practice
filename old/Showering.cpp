#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int number, s_time, min_for_day;
        cin >> number >> s_time >> min_for_day;
        int last_end = 0;
        bool can_showering = 0;
        // vector<int> time(min_for_day + 1, 0);

        while(number--)
        {
            int l, r;
            cin >> l >> r;

            int gap = l - last_end;

            if(gap>=s_time)
            {
                can_showering = 1;
                break;
            }
            // for (int i = l; i <= r;i++)
            // {
            //     time[i] = 1;
            // }
            last_end = r;
        }
        if(!can_showering && (min_for_day - last_end) >= s_time)
            {
                can_showering = 1;
            }
        if(can_showering) 
            {
                cout << "Yes" << endl;
            } 
        else 
            {
                cout << "No" << endl;
            }
    }

    //     int max_time = 0;
    //     int result = 0;
    //     for (int i = 1; i <= min_for_day;i++)
    //     {
    //         if(time[i]!=1)
    //         {
    //             max_time++;
    //         }
            
    //         if(time[i]==1)
    //         {
    //             result = max(result, max_time);
    //             max_time=0;
    //         }
    //     }

    //     result = max(result, max_time);

    //     if(result>=s_time)
    //     {
    //         cout << "Yes" << endl;
    //     }
    //     else{
    //         cout << "No" << endl;
    //     }
    // }


    return 0;
}
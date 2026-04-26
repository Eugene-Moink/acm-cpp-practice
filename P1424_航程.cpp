#include<bits/stdc++.h>
using namespace std;

int main()
{
    int weekday;
    cin >> weekday;
    int days;
    cin >> days;

    int total_weeks = days / 7;

    long long first_part = total_weeks * 5 * 250;

    int remaining_days = days % 7;
    long long second_part = 0;

    for (int i = 0; i < remaining_days;i++)
    {
       
        if(weekday==8)
        {
            weekday = 1;
        }
        if(weekday==6||weekday==7)
        {
           second_part += 0;
        }
        else
        {
            second_part += 250;
        }

        weekday++;
    }

    long long total = first_part + second_part;

    cout << total << endl;

    return 0;
}
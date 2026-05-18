#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool is_leap(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    int result = 0;

    int date_1, date_2;
    cin >> date_1 >> date_2;

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int year_1 = date_1 / 10000;
    int year_2 = date_2 / 10000;
    for(int current_year = year_1; current_year <= year_2; current_year++) 
    {
        int a = current_year / 1000;      
        int b = (current_year / 100) % 10; 
        int c = (current_year / 10) % 10;  
        int d = current_year % 10;         

        int month = d * 10 + c;    
        int day = b * 10 + a;  

        if(month < 1 || month > 12) continue;
        
        if(month == 2) 
        {
            if(is_leap(current_year)) 
            {
                if(day < 1 || day > 29) continue;  
            } 
            else 
            {
                if(day < 1 || day > 28) continue;  
            }
        } 
        
        else 
        {
            if(day < 1 || day > days_in_month[month]) continue;
        }
        
        int full_date = current_year * 10000 + month * 100 + day;
        if(full_date >= date_1 && full_date <= date_2) 
        {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}
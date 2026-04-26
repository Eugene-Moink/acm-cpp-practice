#include<bits/stdc++.h>
using namespace std;

int main()
{
    string number;
    cin >> number;

    double cnt = 0;
    for (int i = 0; i < number.size(); i++)
    {
        if(number[i] == '2')
        {
            cnt++;
        }
    }

    int digit_count = number.size();
    bool is_negative = false;

    if (number[0] == '-')
    {
        is_negative = true;
        digit_count--;
    }

    double result = cnt / digit_count;

    if(is_negative)
    {
        result *= 1.5;
    }

    char last_digit_char = number.back();
    if ((last_digit_char - '0') % 2 == 0)
    {
        result *= 2;
    }

    printf("%.2f%%\n", result * 100);

    return 0;
}
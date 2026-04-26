#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ISBN;
    cin >> ISBN;
    int sum = 0;
    int cnt = 1;
    for(int i = 0; i < ISBN.size();i++)
        {
            char c = ISBN[i];
            if(c != '-') 
            {
                sum += (c - '0') * cnt;
                cnt++;
            }

            if(cnt>9)
            {
                break;
            }
        }

    int temp = sum % 11;
    char calculated_check_char;
    if(temp==10)
    {
        calculated_check_char = 'X';
    }
    else
    {
        calculated_check_char = '0' + temp;
    }

    char actual_check_char = ISBN.back();

    if(calculated_check_char == actual_check_char) 
    {
        cout << "Right" << endl;
    }

    else
    {
        ISBN.pop_back();
        ISBN.push_back(calculated_check_char);
        cout << ISBN << endl;
    }
    
    return 0;
}
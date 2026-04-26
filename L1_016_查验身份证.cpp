#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int temp[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    
    int error_count = 0;

    for (int i = 0; i < n; i++) 
    {
        long long sum = 0;
        string id;
        cin >> id;

        bool is_valid_format = true;
        
        for (int j = 0; j < 17; j++) 
        {
            if (!isdigit(id[j])) 
            {
                is_valid_format = false;
                break;
            }
            int now_number = id[j] - '0';
            sum += now_number * temp[j];
        }

        if (!is_valid_format) 
        {
            cout << id << endl;
            error_count++;
            continue;
        }

        int temp_1 = sum % 11;
        char temp_2 = id[17];
        char check_code[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

        if(temp_2 == check_code[temp_1]) 
        {
            continue;
        } 
        else 
        {
            cout << id << endl;
            error_count++;
        }
    }

    if(error_count == 0) 
    {
        cout << "All passed" << endl;
    }

    return 0;
}
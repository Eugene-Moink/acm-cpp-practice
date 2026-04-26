#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    char c;
    cin >> n >> c;

    int total_stars_needed = 0;
    int max_width = 1;
    
    while(true) 
    {
        int stars_in_upper_half = ((max_width + 1) / 2) * ((max_width + 1) / 2);
        int total_for_current_size = 2 * stars_in_upper_half - 1;
        
        if(total_for_current_size <= n) 
        {
            max_width += 2;
        } 
        else 
        {
            max_width -= 2;
            break;
        }
        
        if (max_width > 1001) 
        {
            max_width -= 2;
            break;
        }
    }
    
    if (n == 1) 
    {
        max_width = 1;
    }

    int stars_in_upper_half_final = ((max_width + 1) / 2) * ((max_width + 1) / 2);
    int total_used = 2 * stars_in_upper_half_final - 1;
    int remaining = n - total_used;

    for (int i = max_width; i >= 1; i -= 2) 
    {
        for (int space = 0; space < (max_width - i) / 2; space++) 
        {
            cout << " ";
        }
        for (int star = 0; star < i; star++) 
        {
            cout << c;
        }
        cout << endl;
    }

    for (int i = 3; i <= max_width; i += 2) 
    {
        for (int space = 0; space < (max_width - i) / 2; space++) 
        {
            cout << " ";
        }
        for (int star = 0; star < i; star++) 
        {
            cout << c;
        }
        cout << endl;
    }

    cout << remaining << endl;

    return 0;
}
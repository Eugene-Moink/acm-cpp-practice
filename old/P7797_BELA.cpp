#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    char B;
    cin >> n >> B;
    
    int total = 0;
    for(int i = 0; i < 4 * n; i++) 
    {
        string s;
        cin >> s;
        char card = s[0];  
        char suit = s[1];  
        
        if(suit == B) 
        {
            switch(card) {
                case 'A': total += 11; break;
                case 'K': total += 4; break;
                case 'Q': total += 3; break;
                case 'J': total += 20; break;
                case 'T': total += 10; break;
                case '9': total += 14; break;
                case '8': total += 0; break;
                case '7': total += 0; break;
            }
        }
        else 
        {
            switch(card) {
                case 'A': total += 11; break;
                case 'K': total += 4; break;
                case 'Q': total += 3; break;
                case 'J': total += 2; break; 
                case 'T': total += 10; break;
                case '9': total += 0; break;  
                case '8': total += 0; break;
                case '7': total += 0; break;
            }
        }
    }
    
    cout << total << endl;
    return 0;
}
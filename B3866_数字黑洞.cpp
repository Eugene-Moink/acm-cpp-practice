#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int count = 0;
    while(n != 495) {
        string s = to_string(n);
        while(s.length() < 3) {
            s = "0" + s;
        }
        
        string temp = s;
        sort(temp.begin(), temp.end());
        int min_val = stoi(temp);
        
        temp = s;
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        int max_val = stoi(temp);
        
        n = max_val - min_val;
        count++;
    }
    
    cout << count << endl;
    return 0;
}
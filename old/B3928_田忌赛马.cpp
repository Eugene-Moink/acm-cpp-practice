#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> your(n), tianji(n);
    
    for(int i = 0; i < n; i++) 
    {
        cin >> your[i];
    }
    
    for(int i = 0; i < n; i++) 
    {
        cin >> tianji[i];
    }
    
    sort(your.begin(), your.end());
    
    int left = 0, right = n - 1, wins = 0;
    
    for(int i = 0; i < n; i++) 
    {
        if(your[right] > tianji[i]) 
        {
            wins++;
            right--;
        } 
        else 
        {
            if(your[left] > tianji[i]) 
            {
                wins++;
                left++;
            } else {
                left++;
            }
        }
    }
    
    cout << wins << endl;
    return 0;
}